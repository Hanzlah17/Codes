#include<iostream>

#include<unistd.h>

#include<fcntl.h>

#include<cstring>

#include<sys/wait.h>

#include<vector>

#include<string>

using namespace std;

//-------------------------------------------//

vector<string> SplitCommands(string command)

{

    int size = command.size();

    vector<string> res;

    string str;

    for (int i = 0;i < size;i++)

    {

        if (command[i] != '|')

        {

            str += command[i];

        }

        else

        {

            str.pop_back(); //removing space from the end of command part

            res.push_back(str);

            str.clear();

            i++;// extra increment so that space could be removed after |

        }

    }

    res.push_back(str);

    return res;

}

//--------------------------------//

char** tokenize(string command)

{

    int wordCount = 1;

    for (int i = 0;i < command.length();i++)

    {

        if (command[i] == ' ')

        {

            wordCount++;

        }

    }

    char** args = new char* [wordCount + 1];

    char buffer[100];

    int j = 0;int k = 0;

    for (int i = 0;i < command.length();i++)

    {

        if (command[i] != ' ')

        {

            buffer[j] = command[i];

            j++;

        }

        else

        {

            buffer[j] = '\0';

            j++;

            args[k] = new char[j + 1];

            strcpy(args[k], buffer);

            k++;

            j = 0;

        }

    }

    buffer[j] = '\0';

    j++;

    args[k] = new char[j + 1];

    strcpy(args[k], buffer);

    args[k + 1] = NULL;

    return args;

}

int main()

{

    vector<string> history(10); // History buffer of size 10

    int count_history = 0;     // Total number of commands entered

    int previousFD; //previous read end of the pipe

    int pipefd[2];

    pid_t p;

    while (true)

    {

        string command;

        cout << "Enter a command: ";

        getline(cin, command);

        if (command == "exit")

        {

            break;

        }

        // Handle history display

        if (command == "history")

        {

            if (count_history == 0)

            {

                cout << "No Commands in history\n";

                continue;

            }

            //display commands

            int start = count_history - 1;

            int end = max(count_history - 10, 0);

            for (int i = start; i >= end; --i)

            {

                cout << (start - i + 1) << ": " << history[i % 10] << endl;

            }

            continue;

        }

        // Handle the !! and !N commands

        if (command == "!!")

        {

            if (count_history == 0)

            {

                cout << "No commands in history." << endl;

                continue;

            }

            command = history[(count_history - 1) % 10];

            cout << "\n--------------EXECUTING " << command << " FROM HISTORY---------------\n";

        }

        else if (command[0] == '!' && command.size() > 1 && isdigit(command[1]))

        {

            int cmd_number = stoi(command.substr(1)) - 1;

            if (cmd_number < 0 || cmd_number >= count_history || cmd_number >= 10)

            {

                cout << "No such command in history." << endl;

                continue;

            }

            command = history[(count_history - 1 - cmd_number) % 10];

            cout << "\n--------------EXECUTING " << command << " FROM HISTORY---------------\n";

        }

        history[count_history % 10] = command;

        count_history++;

        bool background = false;

        if (command[command.length() - 1] == '&')

        {

            background = true;

            command.pop_back();

        }

        vector<string> splitCommands;

        splitCommands = SplitCommands(command); //split commands based on pipes

        int totalCommands = splitCommands.size(); //check how many commands are there

        for (int k = 0;k < totalCommands;k++)

        {

            // Only set up pipes if there are multiple commands

            if (totalCommands > 1)

            {

                if (k < totalCommands - 1)

                {

                    if (pipe(pipefd) == -1)

                    {

                        perror("pipe");

                        exit(EXIT_FAILURE);

                    }

                }

            }

            char** args = tokenize(splitCommands[k]);

            //redirection

            int in = -1;

            int out = -1;

            for (int i = 0; args[i] != NULL; i++)

            {

                if (strcmp(args[i], "<") == 0)

                {

                    in = i + 1;

                    args[i] = NULL;

                }

                else if (strcmp(args[i], ">") == 0)

                {

                    out = i + 1;

                    args[i] = NULL;

                }

            }

            p = fork();

            if (p > 0)

            {

                if (!background)

                {

                        wait(NULL);

                }

                if (totalCommands > 1)

                {

                     if (k > 0)

                     {

                         close(previousFD);  // Close the previous read end

                     }

                     if (k < totalCommands - 1)

                     {

                         close(pipefd[1]);  // Always close the write end in the parent

                         previousFD = pipefd[0];  // Save the read end to be the input for the next command

                     }

                }



            }

            else if (p == 0)

            {

               if (totalCommands > 1)

               {

                   if (k == 0)

                   {

                       // First command

                       dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the write end of the pipe

                       close(pipefd[0]); // Close the unused read end

                   }

                   else if (k == totalCommands - 1)

                   {

                       // Last command

                       dup2(previousFD, STDIN_FILENO); // Redirect stdin to read from the previous pipe

                   }

                   else

                   {

                        // Middle commands

                        dup2(previousFD, STDIN_FILENO);  // Redirect stdin from the previous pipe

                        dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to the next pipe

                        close(pipefd[0]); // Close the unused read end

                   }

               }

               if (in != -1)

               {

                   int fd = open(args[in], O_RDONLY);

                   if (fd < 0)

                   {

                       perror("Input redirection failed");

                       exit(1);

                   }

                   dup2(fd, 0);

                   close(fd);

               }

               if (out != -1)

               {

                   int fd = open(args[out], O_WRONLY | O_CREAT | O_APPEND, 0666);

                   if (fd < 0)

                   {

                       perror("Output redirection failed");

                       exit(1);

                   }

                   dup2(fd, 1); // Redirect stdout to the file

                   close(fd);

               }

               execvp(args[0], args);

               perror("execvp failed");

               exit(1);

            }

            else

            {

               perror("Fork failed");

               exit(1);

            }

        }

    }

    return 0;

}
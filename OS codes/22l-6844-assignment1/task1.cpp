#include<iostream>

#include<unistd.h>

#include<fcntl.h>

#include<cstring>

#include<sys/wait.h>

#include<vector>

#include<string>

using namespace std;



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

pid_t p;

while(true)

{

	string command;

	cout << "Enter a command: ";

	getline(cin,command);

	if(command=="exit")

	{

   		break;

	}

	bool background = false;

        if (command[command.length() - 1] == '&')

        {

            background = true;

            command.pop_back();

        }

	char** args=tokenize(command);

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



p=fork();

if(p>0)

{

	if (!background)

        {

            wait(NULL);

        }

}

else if(p==0)

{

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

                int fd = open(args[out], O_WRONLY | O_CREAT | O_APPEND,0666);

                if (fd < 0)

                {

                    perror("Output redirection failed");

                    exit(1);

                }

                dup2(fd, 1); // Redirect stdout to the file

                close(fd);

            }



execvp(args[0],args);

perror("execvp failed");

exit(1);

}

else

{

  perror("Fork failed");

  exit(1);

}

}

return 0;

}
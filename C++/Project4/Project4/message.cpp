#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>


using namespace std;

void clearScreen() {
    COORD cursorPosition = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void woho()
{
    
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

   
    string text = "HAPPY BIRTHDAY MY APRICITY";
    int x = 0, y = 0, dx = 1, dy = 1;
    int i = 0;

    
    int colors[] = { 12, 10, 11, 13, 14, 9, 15 };

    
    while (i < 100) {
        
        clearScreen();

        
        int colorCode = colors[rand() % 7];
        SetConsoleTextAttribute(consoleHandle, colorCode);
        COORD cursorPosition = { x, y };
        SetConsoleCursorPosition(consoleHandle, cursorPosition);
        cout << text;

        
        x += dx;
        y += dy;
        if (x + text.size() >= 80 || x < 0) {
            dx *= -1;
        }
        if (y >= 25 || y < 0) {
            dy *= -1;
        }
        i++;
        
        Sleep(50);
    }
}
void woho(int a)
{
   
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    string text = "CHL NIKL AB ZADA FREE NA HU";
    int x = 0, y = 0, dx = 1, dy = 1;
    int i = 0;

    
    int colors[] = { 12, 10, 11, 13, 14, 9, 15 };

        while (i < 100) 
        {
        
        clearScreen();

        
        int colorCode = colors[rand() % 7];
        SetConsoleTextAttribute(consoleHandle, colorCode);
        COORD cursorPosition = { x, y };
        SetConsoleCursorPosition(consoleHandle, cursorPosition);
        cout << text;

        
        x += dx;
        y += dy;
        if (x + text.size() >= 80 || x < 0) {
            dx *= -1;
        }
        if (y >= 25 || y < 0) {
            dy *= -1;
        }
        i++;
       
        Sleep(50);
    }
}
void woho(float a)
{
    
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

   
    string text = "FUCK YOU!!!!!!!!!!LAIBABABBABABBABBABABBA!!!!!!!!!!";
    int x = 0, y = 0, dx = 1, dy = 1;
    int i = 0;

    int colors[] = { 12, 10, 11, 13, 14, 9, 15 };

   
    while (i < 100) {
        
        clearScreen();

       
        int colorCode = colors[rand() % 7];
        SetConsoleTextAttribute(consoleHandle, colorCode);
        COORD cursorPosition = { x, y };
        SetConsoleCursorPosition(consoleHandle, cursorPosition);
        cout << text;

        
        x += dx;
        y += dy;
        if (x + text.size() >= 80 || x < 0) {
            dx *= -1;
        }
        if (y >= 25 || y < 0) {
            dy *= -1;
        }
        i++;
        
        Sleep(50);
    }
}

void setTextColor(int colorCode) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, colorCode);
}

void drawHeart(int x, int y, int colorCode) {
    setTextColor(colorCode);

    string heart[6] = {
        "  *   *  ",
        " *** *** ",
        "*********",
        " ******* ",
        "  *****  ",
        "   ***   "
    };

    for (int i = 0; i < 6; i++) {
        COORD cursorPosition = { x, y + i };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        cout << heart[i];
    }
}

int random(int min, int max) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    return rand() % (max - min + 1) + min;
}
void ClearScreen() {
    system("cls");
}

void myheart()
{
    srand(time(0));

    string heart[6] = {
        "I CLIMB EVERY MOUNTAIN",
        "    AND SWIM EVERY OCEAN",
        "JUST TO BE WITH YOU",
        "    AND WHAT I'VE BROKEN",
        "CAUSE I NEED YOU TO SEE IT",
        "       THAT YOU ARE THE REASON       "
    };
    string colors[5] = {
        "\033[31m",
        "\033[32m",
        "\033[33m",
        "\033[34m",
        "\033[35m"
    };
    int x[20], y[20], dx[20], dy[20],color[20];
    int i, j;

    for (i = 0; i < 20; i++) {
        x[i] = rand() % 70;
        y[i] = rand() % 20;
        dx[i] = (rand() % 2) * 2 - 1;
        dy[i] = (rand() % 2) * 2 - 1;
        color[i] = rand() % 5;
    }
    int i1 = 0;
    while (i1<1) 
    {
        ClearScreen();

        for (i = 0; i < 20; i++) {
            for (j = 0; j < y[i]; j++) {
                cout << endl;
            }

            for (j = 0; j < 6; j++) {
                for (int k = 0; k < x[i]; k++) {
                    cout << " ";
                }
                cout << colors[color[i]] << heart[j] << "\033[0m" << endl;
                Sleep(120);
            }

            x[i] += dx[i];
            y[i] += dy[i];

            if (x[i] == 70 || x[i] == 0) {
                dx[i] *= -1;
            }
            if (y[i] == 20 || y[i] == 0) {
                dy[i] *= -1;
            }
        }
        i1++;
        Sleep(50);
    }
}
void myballoons()
{
    srand(time(0));

    string balloon[5] = {
        "YOU ARE MY BITCH",
        "     YOU ARE MY SUNSHINE",
        "YOU ARE MY DARLIN'",
        "     YOU ARE ONLY MINE",
        " `<3`"
    };

    string colors[5] = {
        "\033[31m",
        "\033[32m",
        "\033[33m",
        "\033[34m",
        "\033[35m"
    };

    int x[20], y[20], dx[20], dy[20], color[20];
    int i, j;

    for (i = 0; i < 20; i++) {
        x[i] = rand() % 70;
        y[i] = rand() % 20;
        dx[i] = (rand() % 2) * 2 - 1;
        dy[i] = (rand() % 2) * 2 - 1;
        color[i] = rand() % 5;
    }
    int i1 = 0;
    while (i1<1) {
        ClearScreen();

        for (i = 0; i < 20; i++) {
            for (j = 0; j < y[i]; j++) {
                cout << endl;
            }

            for (j = 0; j < 5; j++) 
            {
                for (int k = 0; k < x[i]; k++) {
                    cout << " ";
                }
                cout << colors[color[i]] << balloon[j] << "\033[0m" << endl;
                Sleep(120);
            }

            x[i] += dx[i];
            y[i] += dy[i];

            if (x[i] == 70 || x[i] == 0) {
                dx[i] *= -1;
            }
            if (y[i] == 20 || y[i] == 0) {
                dy[i] *= -1;
            }
        }
        i1++;
        Sleep(50);
    }
}
bool matchPassword() 
{
    string correctname = "laiba";
    string correctname1 = "LAIBA";
    string correctname2 = "Laiba";
    string correctPassword = "IamyourBitch";  
    string name2 = "Babes";
    string name;
    cout << "Enter your first name to see the message:";
    cin >> name;
    if (name == correctname || name == correctname1 || name==correctname2)
    {
        int numAttempts = 0;
        while (true)
        {
            cout << "Enter your password(without spaces), " << name2 << ": ";
            string enteredPassword;
            cin >> enteredPassword;

            if (enteredPassword == correctPassword)
            {
                return true;
            }
            else
            {
                numAttempts++;
                if (numAttempts == 1) {
                    cout << "Incorrect password. Here's a hint: the password starts with \"" << correctPassword.substr(0, 4) << "\"" << endl;
                }
                else if (numAttempts == 2) {
                    cout << "Incorrect password. Here's another hint: the password ends with \"" << correctPassword.substr(correctPassword.size() - 3, 3) << "\"" << endl;
                }
                else
                {
                    cout << "The password is \"IamyourBitch\". YOU DUMB BITCH." << endl;
                }
            }
        }
    }
    return false;
}
void QA()
{
    string yes = "yes";
    string answer;
    cout << "\nFor the following questions,answer with a yes/no although i know your answers already\n";
    Sleep(5000);
    system("cls");
    cout << "Am I the best person alive?\n";
    cin >> answer;
    if (answer == yes)
    {
        cout << "Mean bitch acting nice today,oooh mood hy ;)\n";
    }
    else
    {
        cout << "I'll take that as yes\n";
    }
    Sleep(5000);
    system("cls");
    cout << "Am I your favourite person?\n";
    cin >> answer;
    if (answer == yes)
    {
        cout << "you are my fav too sunshine\n";
    }
    else
    {
        cout << "I'll take that as yes\n";
    }
    Sleep(5000);
    system("cls");
    cout << "Are u a mean bitch?\n";
    cin >> answer;
    if (answer == yes)
    {
        cout << "But still you are mine ;)\n";
    }
    else
    {
        cout << "I'll take that as yes\n";
    }
    Sleep(5000);
    system("cls");
    cout << "Will you sing for me\n";
    cin >> answer;
    if (answer == yes)
    {
        cout << "Ary!! Pyar hu jaye ga mjhy <3\n";
    }
    else
    {
        cout << "I'll take that as yes\n";
    }
    Sleep(5000);
    system("cls");
    cout << "Will you go on a date with me?\n";
    cin >> answer;
    if (answer == yes)
    {
        cout << "GARI KI CHABI KAHA HY??????\n";
    }
    else
    {
        cout << "I'll take that as yes\n";
        cout << "\nGARI KI CHABI KAHA HY??????\n";
    }
    Sleep(5000);
    system("cls");
    cout << "Since you love me this much as your asnwers have suggested\n*whispers*\nI know you are thinking what a self obsessed bitch\n";
    cout << "\nPickup line to make your day special\n";
    cout << "\nRoses are red, violets are blue, it's your birthday today, and I'm so glad I have a cheesy bitch like you!\n";
    cout << "\n*whisper*\nStop making disgusted face\n";
    cout << "*whispers*\nThank you for existing my bitch <3";
}



int main()
{
    if (matchPassword())
    {
        /*system("cls");
        float a = 1.2;
        woho();
        system("cls");
        myheart();
        system("cls");
        myballoons();
        system("cls");
        woho(1);
        system("cls");
        woho(a);
        system("cls");*/
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 7);
        QA();
        Sleep(15000);
        system("cls");
        cout << "Search on Youtube \"Ai higuchi  \"Akuma no ko\"  Anime Special Ver.\"\n";
        cout << "Play the video from \"0.50-1.16\"\n";
        cout << "Note: Don't forget to turn on English Captions\n\n\n";
    }
    else 
    {
        cout << "\n\nSorry You are not my Sunshine\n\n";
        cout << "\nAccess Denied!!!!!!!!!\n";
    }
    return 0;
}
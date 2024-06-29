#include <ncurses.h>

#include<pthread.h>

#include <cmath>

#include <unistd.h>

#include <csignal>

#include <cstdlib>

using namespace std;

void gotoxy(int x, int y) {

    move(y, x); // ncurses uses (y, x) instead of (x, y)

}



bool isCursorKeyPressed(int& whichKey) {

    int ch = getch();

    if (ch != ERR) {

        switch (ch) {

            case KEY_LEFT:

                whichKey = 1; // Left key

                return true;

            case KEY_UP:

                whichKey = 2; // Up key for the left paddle

                return true;

            case KEY_RIGHT:

                whichKey = 3; // Right key

                return true;

            case KEY_DOWN:

                whichKey = 4; // Down key for the left paddle

                return true;

            case 'w':

                whichKey = 5; // 'u' key for the right paddle up

                return true;

            case 's':

                whichKey = 6; // 'd' key for the right paddle down

                return true;

            case ' ':

                whichKey = 0; // Spacebar

                return true;

        }

    }

    return false;

}

void myRectangle(int x1, int y1, int x2, int y2) {

    for (int y = y1; y <= y2; ++y) {

        for (int x = x1; x <= x2; ++x) {

            if (y == y1 || y == y2 || x == x1 || x == x2)

                mvaddch(y, x, '-');

            else

                mvaddch(y, x, ' '); // Fill the rectangle

        }

    }

}



// Constants for the game dimensions and paddle size

const int fieldWidth = 80;

const int fieldHeight = 24;

const int paddleWidth = 1;

const int paddleHeight = 4;

const int ballSize=1;

const char ballChar = 'O'; 



// Structure to represent a paddle

struct Paddle 

{

    int x;

    int y;

};



// Structure to represent the ball

struct Ball 

{

    int x;

    int y;

    int velX;

    int velY;

};



// Initialize paddles and ball

Paddle leftPaddle{2, fieldHeight / 2 - paddleHeight / 2};

Paddle rightPaddle{fieldWidth - 3, fieldHeight / 2 - paddleHeight / 2};

Ball ball{fieldWidth / 2, fieldHeight / 2, 1, 1};

int scoreP1 = 9, scoreP2 = 0;



// Initialize the ncurses window

void finish(int sig) 

{

    endwin(); // Restore the terminal to its original settings

    // Additional cleanup if necessary

    exit(0); // Exit program

}



void initGame() {

    initscr();           // Start curses mode

    raw();               // Disable line buffering

    keypad(stdscr, TRUE); // We get F1, F2 etc..

    noecho();            // Don't echo() while we do getch

    curs_set(0);         // Hide the cursor

    nodelay(stdscr, TRUE); // Non-blocking getch

    signal(SIGINT, finish);

}



void* drawGame(void* args) 

{

    clear();



    //left paddle

    myRectangle(leftPaddle.x, leftPaddle.y, leftPaddle.x + paddleWidth, leftPaddle.y + paddleHeight);



    //right paddle

    myRectangle(rightPaddle.x, rightPaddle.y, rightPaddle.x + paddleWidth, rightPaddle.y + paddleHeight);



    // Draw ball

    mvaddch(ball.y, ball.x, ballChar);



    //scores

    mvprintw(0, 0, "Score P1: %d Score P2: %d", scoreP1, scoreP2);



    refresh(); 

    return NULL;

}



void* movePaddles(void* args) 

{

    while(true)

    {

        int key;

        while (isCursorKeyPressed(key)) 

        {

            switch (key) 

            {

                case 0: // ' ' key for the exit

                    finish(0);

                case 5: // Up key for the left paddle

                    if (leftPaddle.y > 0) 

                    {

                        leftPaddle.y--;

                    }

                    break;

                case 6: // Down key for the left paddle

                    if (leftPaddle.y + paddleHeight < fieldHeight)

                    {

                        leftPaddle.y++;

                    }

                    break;

                case 2: // 'u' key for the right paddle up

                    if (rightPaddle.y > 0)

                    {

                        rightPaddle.y--;

                    }

                    break;

                case 4: // 'd' key for the right paddle down

                    if (rightPaddle.y + paddleHeight < fieldHeight)

                    {

                        rightPaddle.y++;

                    }

                    break;

            }

        }

    }

    return NULL;

}



// Function to update the ball position and check for collisions

void* updateBall(void* args) 

{

    ball.x += ball.velX;

    ball.y += ball.velY;



    if (ball.y <= 0 || ball.y >= fieldHeight - 1)

    {

        ball.velY = -ball.velY;

    }



    // Collision with left paddle

    if (ball.x == leftPaddle.x + paddleWidth && ball.y >= leftPaddle.y && ball.y <= leftPaddle.y + paddleHeight)

    {

        ball.velX = -ball.velX;

        ball.x = leftPaddle.x + paddleWidth;

    }



    // Collision detection with right paddle

    if (ball.x == rightPaddle.x - paddleWidth && ball.y >= rightPaddle.y && ball.y <= rightPaddle.y + paddleHeight) 

    {

        ball.velX = -ball.velX;

        ball.x = rightPaddle.x - paddleWidth;

    }



    // Update scores 

    if (ball.x <= 0) 

    {

        scoreP2++;

        ball.x = fieldWidth / 2;

        ball.y = fieldHeight / 2;

        ball.velX = 1;

        ball.velY = (rand() % 2) * 2 - 1;

    }



    if (ball.x >= fieldWidth - 1) 

    {

        scoreP1++;

        ball.x = fieldWidth / 2;

        ball.y = fieldHeight / 2;

        ball.velX = -1; 

        ball.velY = (rand() % 2) * 2 - 1; 

    }

    usleep(100000);

    return NULL;

}

void PrintWinner()

{

    clear();

    if(scoreP1>=10)

    {

        mvprintw(0, 0, "Player1 is winner");

    }  

    else

    {

        mvprintw(0, 0, "Player2 is winner");

    }

    refresh(); 

    usleep(5000000);

}



int main() 

{

    initGame();

    pthread_t paddle_id;

    pthread_t ball_id;

    pthread_t game_id;

    pthread_create(&paddle_id,0,&movePaddles,NULL);

    while (scoreP1 < 10 && scoreP2 < 10) 

    {

        pthread_create(&game_id,0,&drawGame,NULL);

        pthread_join(game_id,NULL);

        pthread_create(&ball_id,0,&updateBall,NULL);

        pthread_join(ball_id,NULL);

    }

    PrintWinner();

    finish(0);

    return 0;

}


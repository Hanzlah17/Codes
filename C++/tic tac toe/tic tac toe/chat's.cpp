//#include <iostream>
//#include <vector>
//#include <climits>
//using namespace std;
//
//const int EMPTY = 0;
//const int PLAYER1 = 1;
//const int PLAYER2 = 2;
//
//void printBoard(const vector<vector<int>>& board) {
//    for (const auto& row : board) {
//        for (int cell : row) {
//            if (cell == EMPTY)
//                cout << "_ ";
//            else if (cell == PLAYER1)
//                cout << "X ";
//            else if (cell == PLAYER2)
//                cout << "O ";
//        }
//        cout << endl;
//    }
//}
//
//bool isBoardFull(const vector<vector<int>>& board) {
//    for (const auto& row : board) {
//        for (int cell : row) {
//            if (cell == EMPTY)
//                return false;
//        }
//    }
//    return true;
//}
//
//bool isGameOver(const vector<vector<int>>& board, int& winner) {
//    const int SIZE = board.size();
//
//    // Check rows
//    for (int i = 0; i < SIZE; ++i) {
//        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != EMPTY) {
//            winner = board[i][0];
//            return true;
//        }
//    }
//
//    // Check columns
//    for (int i = 0; i < SIZE; ++i) {
//        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != EMPTY) {
//            winner = board[0][i];
//            return true;
//        }
//    }
//
//    // Check diagonals
//    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY) {
//        winner = board[0][0];
//        return true;
//    }
//
//    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != EMPTY) {
//        winner = board[0][2];
//        return true;
//    }
//
//    // Check if the board is full (draw)
//    if (isBoardFull(board)) {
//        winner = 0; // Draw
//        return true;
//    }
//
//    return false;
//}
//
//int evaluate(const vector<vector<int>>& board, int depth) {
//    int winner;
//    if (isGameOver(board, winner)) {
//        if (winner == PLAYER2)
//            return 1; // Computer wins
//        else if (winner == PLAYER1)
//            return -1; // Human wins
//        else
//            return 0; // Draw
//    }
//
//    return 0; // Game is not over
//}
//
//int minimax(vector<vector<int>>& board, int depth, bool isMaximizing) {
//    int score = evaluate(board, depth);
//
//    if (score != 0)
//        return score;
//
//    if (isMaximizing) {
//        int maxScore = INT_MIN;
//        for (int i = 0; i < 3; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                if (board[i][j] == EMPTY) {
//                    board[i][j] = PLAYER2;
//                    int currentScore = minimax(board, depth + 1, false);
//                    board[i][j] = EMPTY;
//                    maxScore = max(maxScore, currentScore);
//                }
//            }
//        }
//        return maxScore;
//    }
//    else {
//        int minScore = INT_MAX;
//        for (int i = 0; i < 3; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                if (board[i][j] == EMPTY) {
//                    board[i][j] = PLAYER1;
//                    int currentScore = minimax(board, depth + 1, true);
//                    board[i][j] = EMPTY;
//                    minScore = min(minScore, currentScore);
//                }
//            }
//        }
//        return minScore;
//    }
//}
//
//void playTurn(vector<vector<int>>& board, int player) {
//    if (player == PLAYER1) {
//        int row, col;
//        cout << "Enter the row number (0-2): ";
//        cin >> row;
//        cout << "Enter the column number (0-2): ";
//        cin >> col;
//
//        while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != EMPTY) {
//            cout << "Invalid move! Enter an empty cell.\n";
//            cout << "Enter the row number (0-2): ";
//            cin >> row;
//            cout << "Enter the column number (0-2): ";
//            cin >> col;
//        }
//
//        board[row][col] = player;
//    }
//    else {
//        int maxScore = INT_MIN;
//        int bestRow = -1, bestCol = -1;
//
//        for (int i = 0; i < 3; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                if (board[i][j] == EMPTY) {
//                    board[i][j] = PLAYER2;
//                    int currentScore = minimax(board, 0, false);
//                    board[i][j] = EMPTY;
//
//                    if (currentScore > maxScore) {
//                        maxScore = currentScore;
//                        bestRow = i;
//                        bestCol = j;
//                    }
//                }
//            }
//        }
//
//        board[bestRow][bestCol] = player;
//        cout << "Computer played: " << bestRow << ", " << bestCol << endl;
//    }
//}
//
//int main() {
//    vector<vector<int>> board(3, vector<int>(3, EMPTY));
//    int currentPlayer = PLAYER1;
//    int winner = 0;
//
//    while (!isGameOver(board, winner)) {
//        printBoard(board);
//        playTurn(board, currentPlayer);
//        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
//    }
//
//    printBoard(board);
//
//    if (winner != 0)
//        cout << "Player " << winner << " wins!" << endl;
//    else
//        cout << "It's a draw!" << endl;
//
//    return 0;
//}

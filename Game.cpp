#include <iostream>
#include <limits>

using namespace std;

char board[3][3] = { {'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'} };

char playerMarker, aiMarker;
bool isTwoPlayer = true; // True = PvP, False = AI mode

// Function to display the board
void displayBoard() {
    cout << "Tic-Tac-Toe Game\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n\n";
}

// Function to check for a win
char checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0]; // Rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i]; // Columns
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0]; // Diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2]; // Reverse Diagonal

    return ' '; // No winner
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false; // Empty spot found
    return true;
}

// Function to make a move
bool makeMove(int choice, char marker) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') return false;

    board[row][col] = marker;
    return true;
}

// AI Minimax function
int minimax(bool isMaximizing) {
    char winner = checkWin();
    if (winner == aiMarker) return 10;
    if (winner == playerMarker) return -10;
    if (checkDraw()) return 0;

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 1; i <= 9; i++) {
            int row = (i - 1) / 3, col = (i - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = aiMarker;
                bestScore = max(bestScore, minimax(false));
                board[row][col] = '1' + i - 1; // Undo move
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 1; i <= 9; i++) {
            int row = (i - 1) / 3, col = (i - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = playerMarker;
                bestScore = min(bestScore, minimax(true));
                board[row][col] = '1' + i - 1; // Undo move
            }
        }
        return bestScore;
    }
}

// AI move
void aiMove() {
    int bestMove = -1, bestScore = numeric_limits<int>::min();
    for (int i = 1; i <= 9; i++) {
        int row = (i - 1) / 3, col = (i - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = aiMarker;
            int score = minimax(false);
            board[row][col] = '1' + i - 1; // Undo move

            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    makeMove(bestMove, aiMarker);
}

// Function to reset the board
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

// Main function
int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Choose mode: 1. Two-Player  2. Play Against AI\n";
    int mode;
    cin >> mode;
    isTwoPlayer = (mode == 1);

    cout << "Choose your marker (X or O): ";
    cin >> playerMarker;
    while (playerMarker != 'X' && playerMarker != 'O') {
        cout << "Invalid choice. Choose 'X' or 'O': ";
        cin >> playerMarker;
    }
    aiMarker = (playerMarker == 'X') ? 'O' : 'X';

    displayBoard();
    int turn = 1; // 1 for player, -1 for AI
    if (!isTwoPlayer && aiMarker == 'X') aiMove(), turn = 1;

    while (true) {
        if (turn == 1) {
            int choice;
            cout << "Your move: ";
            cin >> choice;
            if (!makeMove(choice, playerMarker)) {
                cout << "Invalid move, try again.\n";
                continue;
            }
        } else {
            cout << "AI is thinking...\n";
            aiMove();
        }

        displayBoard();
        char winner = checkWin();
        if (winner == playerMarker) { cout << "Congratulations! You win! 🎉\n"; break; }
        if (winner == aiMarker) { cout << "AI wins! 🤖 Better luck next time.\n"; break; }
        if (checkDraw()) { cout << "It's a draw! 😐\n"; break; }

        turn *= -1; // Switch turn
    }

    cout << "Play again? (y/n): ";
    char playAgain;
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        resetBoard();
        main(); // Restart game
    } else {
        cout << "Thanks for playing! 🎮\n";
    }

    return 0;
}

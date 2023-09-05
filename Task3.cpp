#include <iostream>
using namespace std;

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char currentPlayer = 'X';

void printBoard() {
    cout << "  1   2   3" << endl;
    cout << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  ---------" << endl;
    cout << "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  ---------" << endl;
    cout << "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isMoveValid(int row, int col) {
    bool validRows = (row >= 0) && (row < 3);
    bool validCols = (col >= 0) && (col < 3);
    bool emptyCells = (board[row][col] == ' ');

    return validRows && validCols && emptyCells;
}

bool isBoardFull() {
    bool full = true;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                full = false;
                break;
            }
        }

        if (!full) {
            break;
        }
    }

    return full;
}
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

void resetBoard() {
    memset(board, ' ', sizeof(board));
}


int main() {
    bool playGame = true;

    while (playGame) {
        int row, col;
        bool gameWon = false;
        bool draw = false;

        cout << "TIC-TAC-TOE GAME" << endl;
        printBoard();

        while (!gameWon && !draw) {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (isMoveValid(row - 1, col - 1)) {
                board[row - 1][col - 1] = currentPlayer;
                printBoard();

                if (checkWin()) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameWon = true;
                }
                else if (isBoardFull()) {
                    cout << "It's a draw!" << endl;
                    draw = true;
                }
                else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
            else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        if (playAgain()) {
            resetBoard();
            currentPlayer = 'X';
        }
        else {
            playGame = false;
        }
    }

    cout << "Thank you for playing! Goodbye!" << endl;

    return 0;
}

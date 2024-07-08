#include <iostream>
using namespace std;

char board[3][3];
char player ='X';

void resetBoard() {
    char start ='1';
    for(int i=0; i<3; i++) {
        for(int j =0; j <3; j++) {
            board[i][j] =start++;
        }
    }
}

void drawBoard() {
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
}

bool isWinner() {
    
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    }
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool isDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void takeTurn() {
    int choice;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> choice;

    int row =(choice - 1) / 3;
    int col =(choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        player = (player == 'X') ? 'O' : 'X';
    } else {
        cout << "Invalid move. Try again.\n";
        takeTurn();
    }
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    do {
        resetBoard();
        while (true) {
            drawBoard();
            takeTurn();
            if(isWinner()) {
                drawBoard();
                cout << "Player " << ((player == 'X') ? 'O' : 'X') << " wins!\n";
                break;
            }
            if(isDraw()) {
                drawBoard();
                cout << "It's a draw!\n";
                break;
            }
        }
    } while(playAgain());
    return 0;
}

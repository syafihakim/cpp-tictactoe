#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

// prototype for functions
void initializeBoard();
void drawBoard();
void getInput();
void checkWinHorizontal();
void checkWinVertical();
void checkWinDiagonal();

vector<vector<char>> board;

int player = 1;
char winner = '-';
string debug = "";

int main()
{
    initializeBoard();

    while(winner == '-') {
        system("cls");
        cout << "JOM BUAT" << endl;
        cout << "TIC TAC TOE\n" << endl;
        drawBoard();
        if(player == 1){
            cout << "\nTURN : X";
        } else {
            cout << "\nTURN : O";
        }
        getInput();
        checkWinHorizontal();
        checkWinVertical();
        checkWinDiagonal();
    }
    system("cls");
    cout << "WINNER IS " << winner << endl;
    drawBoard();
    return 0;
}

// check pemenang
void checkWinHorizontal() {
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] &&
           board[i][0] == board[i][2] &&
           board[i][0] != ' ')
           {
                winner = board[i][0];
                debug = "Horizontal";
                return;
           }
    }
}

void checkWinVertical() {
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] &&
           board[0][i] == board[2][i] &&
           board[0][i] != ' ')
           {
                winner = board[0][i];
                debug = "Vertical";
                return;
           }
    }
}
void checkWinDiagonal() {


    // 00 11 22
    // 02 11 20

    if(board[0][0] == board[1][1] &&
       board[0][0] == board[2][2] &&
       board[0][0] != ' ')
        winner = board[0][0];
    else if(
        board[0][2] == board[1][1] &&
        board[0][2] == board[2][0] &&
        board[0][2] != ' ') {
        winner = board[0][2];
    }
}

void getInput() {
    int input;
    input = getch();
    input -= 49;

    // untuk determine dia punya
    // row dan column
    // dalam 2d array
    // kena guna bahagi dan modulus

    int col = input%3;
    int row = input/3;

    cout << row;
    cout << col << endl;

    if(board[row][col] != ' ') return;

    if(player == 1) {
        board[row][col] = 'X';
    } else {
        board[row][col] = 'O';
    }

    player *= -1;

}

void initializeBoard() {
   vector<char> row = {' ', ' ', ' '};

   for(int i=0; i<3; i++) {
        board.push_back(row);
   }

}

void drawBoard() {
    cout << "+---+---+---+" << endl;
    for(int i=0; i<3; i++) {
        vector<char> row = board[i];
        cout << "|";
        for(int j=0; j<3; j++) {
            cout << " ";
            cout << row[j];
            cout << " |";
        }
        cout << endl;
        cout << "+---+---+---+" << endl;
    }
}
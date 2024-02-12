#include <vector>
#include <iostream>

using namespace std;

/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * A sudoku solution must satisfy all of the following rules:
 *  Each of the digits 1-9 must occur exactly once in each row.
 *  Each of the digits 1-9 must occur exactly once in each column.
 *  Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * The '.' character indicates empty cells.
 */

void printBoard(vector<vector<char>> &board){ //print the sudoku grid after solve
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if(col == 3 || col == 6)
                cout << "|";
            cout << board[row][col] <<"  ";
        }
        if(row == 2 || row == 5){
            cout << endl;
            cout << "----------------------------";
        }
        cout << endl;
    }
}

bool isInRow(vector<vector<char>> &board, int row, char c) {
    for (auto x: board[row]) {
        if (x == c) {
            return true;
        }
    }
    return false;
}

bool isInCol(vector<vector<char>> &board, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) {
            return true;
        }
    }
    return false;
}

bool isIn3x3(vector<vector<char>> &board, int boxStartRow, int boxStartCol, char c) {
    for (int i = boxStartRow; i < boxStartRow + 3; i++) {
        for (int j = boxStartCol; j < boxStartCol + 3; j++) {
            if (board[i][j] == c) {
                return true;
            }
        }
    }
    return false;
}

bool isValidPosition(vector<vector<char>> &board, int row, int col, char c) {
    return (!isInRow(board, row, c) &&
            !isInCol(board, col, c) &&
            !isIn3x3(board, row - row % 3, col - col % 3, c)
    );
}

bool getEmptyPosition(vector<vector<char>> &board, int &row, int &col){
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (board[row][col] == '.')
                return true;
    return false;
}

bool sudoku(vector<vector<char>> &board){
    int row, col;
    if (!getEmptyPosition(board, row, col))
        return true;
    for(char c = '1'; c <='9'; c++){
        if(isValidPosition(board, row, col, c)){
            board[row][col] = c;
            if(sudoku(board)){
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board) {
    sudoku(board);
}

int main() {
    std::vector<std::vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };

    printBoard(board);
    solveSudoku(board);
    printBoard(board);
    return 0;
}
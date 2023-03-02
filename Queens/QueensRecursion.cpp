#include <iostream>

// this function finds if there are conflicts 
bool good(bool board[][8], int x, int y) {
    int i = 0;
    int j = 0;

    for (i = 0; i < y; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j]) {
                if (j == x || 
                   (std::abs(j - x) == (y - i))) {
                    return false;
                }
            }
        }
    }
    return true;
}

// this function tries to place a queen and
// after making sure there are no conflicts
// it tries the next row recursively
bool trial(bool board[][8], int n) {
    for (int i = 0; i < 8; i++) {
        board[n][i] = true;
        if (n == 7 && good(board, i, n)) {
            return true;
        }
        else if (n < 7 && good(board, i, n) && trial(board, n + 1)) {
            return true;
        }
        board[n][i] = false;
    }
    return false;
}



int main()
{
    // the board 8 x 8 boolean
    // queens are placed where we have "true"
    // initially make the board empty (all are false)
    bool board[8][8] = {};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = false;
        }
    }

    board[0][0] = true;
    board[1][2] = true;
    board[2][4] = true;
    board[4][3] = true;

    trial(board, 0); //try to place a queen at row 0

    // print the board, it will output 1 for queen 
    // and 0 for empty
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

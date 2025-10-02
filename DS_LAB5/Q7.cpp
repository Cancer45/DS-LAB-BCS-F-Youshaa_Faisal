#include <iostream>

int board[8];

void printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            std::cout << (board[i] == j ? "Q " : ". ");
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        int diffRow = row - i;
        int diffCol = board[i] - col;
        if (diffCol < 0) diffCol = -diffCol;
        if (board[i] == col || diffCol == diffRow)
            return false;
    }
    return true;
}

void solve(int row) {
    if (row == 8) {
        printBoard();
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    solve(0);
    return 0;
}
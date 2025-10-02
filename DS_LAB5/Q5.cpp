#include <iostream>

bool isValid(int grid[9][9], int row, int col, int val) {
    for (int i = 0; i < 9; i++)
        if (grid[row][i] == val || grid[i][col] == val) return false;

    int sr = row - row % 3, sc = col - col % 3;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (grid[sr + r][sc + c] == val) return false;

    return true;
}

bool solve(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isValid(grid, row, col, val)) {
                        grid[row][col] = val;
                        if (solve(grid)) return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(int grid[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++)
            std::cout << grid[r][c] << " ";
        std::cout << "\n";
    }
}

int main() {
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (solve(grid))
        printGrid(grid);
    else
        std::cout << "No solution exists\n";
}
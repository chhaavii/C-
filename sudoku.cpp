#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// Function to display the Sudoku grid with lines
void displayGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0 && i != 0) cout << "------+-------+------\n"; // Horizontal line
        for (int j = 0; j < SIZE; j++) {
            if (j % 3 == 0 && j != 0) cout << "| "; // Vertical line
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed at grid[row][col]
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check the row and column
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {  // Find an empty space
                for (int num = 1; num <= SIZE; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;  // Place the number
                        if (solveSudoku(grid)) {  // Recursively solve
                            return true;
                        }
                        grid[row][col] = 0;  // Backtrack
                    }
                }
                return false;  // No valid number found
            }
        }
    }
    return true;  // Puzzle solved
}

// Main function
int main() {
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku Grid:\n";
    displayGrid(grid);
    
    // Allow user to input values
    cout << "\nInput your values (row, column, number). Enter -1 to stop:\n";
    int row, col, num;
    while (true) {
        cout << "Enter row (0-8), column (0-8), and number (1-9): ";
        cin >> row;
        if (row == -1) break; // Stop input
        cin >> col >> num;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= 9) {
            if (isSafe(grid, row, col, num)) {
                grid[row][col] = num;
                cout << "Value placed successfully.\n";
            } else {
                cout << "This value cannot be placed here!\n";
            }
        } else {
            cout << "Invalid input!\n";
        }
        displayGrid(grid);
    }

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku Grid:\n";
        displayGrid(grid);
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}

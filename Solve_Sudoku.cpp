
#include "Solve_Sudoku.h"
//SUDOKU SOLVING
bool isPresentInCol(int grid[N][N], int col, int num) { //check whether num is present in col or not
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool isPresentInRow(int grid[N][N], int row, int num) { //check whether num is present in row or not
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool isPresentInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    //check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}
void sudokuGrid(int grid[N][N]) { //print the sudoku grid after solve
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        if (row == 2 || row == 5) {
            cout << endl;
            for (int i = 0; i < N; i++)
                cout << "---";
        }
        cout << endl;
    }
}

bool findEmptyPlace(int grid[N][N], int& row, int& col) { //get empty location and update row and column
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0) //marked with 0 is empty
                return true;
    return false;
}
bool isValidPlace(int grid[N][N], int row, int col, int num) {
    //when item not found in col, row and current 3x3 box
    return !isPresentInRow(grid, row, num) && !isPresentInCol(grid, col, num) && !isPresentInBox(grid, row - row % 3,
        col - col % 3, num);
}
bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findEmptyPlace(grid, row, col))
        return true; //when all places are filled
    for (int num = 1; num <= 9; num++) { //valid numbers are 1 - 9
        if (isValidPlace(grid, row, col, num)) { //check validation, if yes, put the number in the grid
            grid[row][col] = num;
            if (solveSudoku(grid)) //recursively go for other rooms in the grid
                return true;
            grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
        }
    }
    return false;
}

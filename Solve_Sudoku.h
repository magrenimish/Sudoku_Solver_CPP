#ifndef SOLVE_SUDOKU_H_
#define SOLVE_SUDOKU_H_
#include<iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include<fstream>
#include<filesystem>
#include <stdio.h>
#define N 9


using namespace std;

bool isPresentInCol(int grid[N][N], int col, int num);
bool isPresentInRow(int grid[N][N], int row, int num);
bool isPresentInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
void sudokuGrid(int grid[N][N]);
bool findEmptyPlace(int grid[N][N], int& row, int& col);
bool isValidPlace(int grid[N][N], int row, int col, int num);
bool solveSudoku(int grid[N][N]);


#endif /* SOLVE_SUDOKU_H_ */
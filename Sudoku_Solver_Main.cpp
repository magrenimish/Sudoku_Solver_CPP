#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
#include <vector>
#include "dataset.h"
#include "hough.h"
#include <string>
#include "Solve_Sudoku.h"
#include "KNN_Digit_Recognition.h"
#include "Crop_Digits.h"
#define N 9

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    //Load the MNIST dataset
    load_dataset();
    
    vector<cv::Mat> Vec(81);
    string path = "./Example_Images/sudoku0.png";
    cout << "\n" << "separating the unsolved sudoku grid into indivdual 81 grid images" << "\n";
    Vec = houghline(path);
    
    vector<cv::Mat> Vec1(81);
    cv::Mat Vec2;
    Mat Vec3;
    cout << "\n" << "removing images that are blank and cropping digits " << "\n";
    for (int a1 = 0; a1 < 81; a1++) {
        Vec3 = Vec[a1];
        Vec2 = trainOCR(Vec3);
        Vec1[a1] = Vec2;
    }
    

    vector<pair<bool, Mat>> Vl(81);
    for (int i = 0; i < 81; i++) {
        if (countNonZero(Vec1[i]) < 1) {
            Vl[i].first = 0; Vl[i].second = Vec1[i];
        }
        else { Vl[i].first = 1; Vl[i].second = Vec1[i]; }
    }
    
    
    cout << "\n" << "Solving Sudoku now" << "\n";
    int *pred;
    pred = Prediction(Vl);
    int a4 = 0;
    int grid[N][N] = {};
    for (size_t i = 0; i < 9; i++) {
        for (size_t j = 0; j < 9; j++) {
            grid[i][j] = *(pred+a4);
            a4++;
        }
    }
    
    cout << "\n" << "Unsolved Sudoku is " << "\n";
    sudokuGrid(grid);

    if (solveSudoku(grid) == true) {
        cout << "\n" << "Solved Sudoku is " << "\n";
        sudokuGrid(grid);
    }
    else
        cout << "No solution exists";
}  

    

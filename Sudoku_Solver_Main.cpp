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
    load_dataset();
    vector<cv::Mat> Vec(81);
    string path = "./Example_Images/sudoku0.png";
    cout << "\n" << "separating the unsolved sudoku grid into indivdual 81 grid images" << "\n";
    Vec = houghline(path);
    //cout << "\n" << "Vec size is " << Vec.size() << "\n";
    
    vector<cv::Mat> Vec1(81);
    cv::Mat Vec2;
    Mat Vec3;
    cout << "\n" << "removing images that are blank and cropping digits " << "\n";
    //cout << "\n" << "Vec1 size is " << Vec1.size() << "\n";
    for (int a1 = 0; a1 < 81; a1++) {
        Vec3 = Vec[a1];
        
        Vec2 = trainOCR(Vec3);
        
    //cout << "\n" << "Vec2 size is " << Vec2.size() << "\n";
    if (countNonZero(Vec2) >= 1) {
        //string vecname = "./crop_images/" + std::to_string(a1 + 1) + ".jpg";
        //imwrite(vecname, Vec2);
    }
    Vec1[a1] = Vec2;
    }
    
    //cout << "\n" << "V size is " << Vec1.size() << "\n";
    vector<pair<bool, Mat>> Vl(81);
    for (int i = 0; i < 81; i++) {
        //cout << "\n" << "Vec1 size is " << Vec1[i].size() << "\n";
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
            //cout << "\n" << "prediction is " << *(pred+a4) << "\n";
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

    

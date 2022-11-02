# Sudoku_Solver_CPP</br>
This repository includes a C++ based implementation of a (9x9) Sudoku Solver </br>
Canny Edge detection and Hough Transform was used to detect the grid and divide the sudoku image into (9x9=81) sub-images</br>
For each sub-image, the kNN algorithm with the MNIST dataset and k=3 is used for digit recognition</br></br>


To use the code, put the string path for one of the unsolved sudoku images from the Example_Images folder in the Sudoku_Solver_Main.cpp file </br>
The code was originally run using Visual Studio 2022

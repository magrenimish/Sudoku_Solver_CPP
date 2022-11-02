# Sudoku_Solver_CPP</br>
This repository includes a C++ based implementation of a (9x9) Sudoku Solver </br>
Canny Edge detection and Hough Transform was used to detect the grid and divide the sudoku image into (9x9=81) sub-images</br>
For each sub-image, the kNN algorithm with the MNIST dataset and k=3 is used for digit recognition</br></br>

Currently the code displays the original unsolved sudoku image and the array of the solved sudoku as follows:</br>
<img align="center" src="https://github.com/magrenimish/Sudoku_Solver_CPP/blob/main/Example_Images/Sudoku0_solved.png" alt="nimish magre" /></a></br>
I am continuing work on accepting the unsolved sudoku image directly from the webcam</br>
and displaying the solved sudoku by displaying the relevant digits on the original image.</br>
To use the code, put the string path for one of the unsolved sudoku images from the Example_Images folder in the Sudoku_Solver_Main.cpp file </br>
The code was originally run using Visual Studio 2022



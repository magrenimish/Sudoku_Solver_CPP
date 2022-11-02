#ifndef KNN_DIGIT_RECOGNITION_H_
#define KNN_DIGIT_RECOGNITION_H_
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
#include <vector>
#include <array>
#include <utility>
#include <algorithm>
#include <string>
#include<fstream>
#include<filesystem>
#include <stdio.h>
//#define N 9
using namespace cv;
using namespace std;

uint32_t distSQ(size_t i, cv::Mat flat, size_t j);
uint8_t predict(size_t i, cv::Mat flat);
int * Prediction(vector<pair<bool, Mat>>& V);



#endif /*KNN_DIGIT_RECOGNITION_H_*/

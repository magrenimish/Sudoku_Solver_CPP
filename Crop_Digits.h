#ifndef CROP_DIGITS_H_
#define CROP_DIGITS_H_
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;
cv::Mat trainOCR(cv::Mat& V);
Mat processInput(Mat img);

#endif /*CROP_DIGITS_H_*/ 
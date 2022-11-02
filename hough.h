#ifndef HOUGH_H_
#define HOUGH_H_
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;

std::vector<cv::Mat> houghline(string filename);

#endif /* HOUGH_H_ */
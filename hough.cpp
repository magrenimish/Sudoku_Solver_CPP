#include "hough.h"


std::vector<cv::Mat> houghline(string filename)
{
    std::vector<cv::Mat> Vec(81);
    int p = 0;
    Mat src = imread(filename, 0);
    Mat dst, cdst;
    Canny(src, dst, 50, 200, 3);
    cvtColor(dst, cdst, COLOR_GRAY2BGR);
    vector<Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 15);

    int minx = 1000, miny = 1000, maxx = 0, maxy = 0;
        for (size_t i = 0; i < lines.size(); i++)
    {
        Vec4i l = lines[i];
        if (l[0] < minx) minx = l[0];
        if (l[1] < miny) miny = l[1];
        if (l[2] > maxx) maxx = l[2];
        if (l[3] > maxy) maxy = l[3];
    }
    /*cout << "\n" << "minx is " << minx << "\n";
    cout << "\n" << "maxy is " << maxy << "\n";
    cout << "\n" << "maxx is " << maxx << "\n";
    cout << "\n" << "miny is " << miny << "\n";*/
    Mat img;
    float w1 = ((maxy - miny) / 9);
    float h1 = ((maxx - minx) / 9);
    int w2 = 0;
    for (float w = miny; w <= maxy-w1; w += w1) {
            for (float q = minx; q <= maxx-h1; q += h1) {
                Mat imcrop = src(Rect(q, w, h1, w1));
                Mat resized_up;
                resize(imcrop, resized_up, Size(28, 28), INTER_LINEAR);
                
                        //string img_name = std::to_string(w2+1) + ".jpg";
                        //imwrite("C:/Users/nimis/source/repos/OpenCV_Course/OpenCV_Course/hough_images/"+img_name, imcrop);
                        Vec[w2] = imcrop;
                        w2 += 1;
                /*imshow("imcrop", imcrop);
                waitKey(200);*/
            }
        } 
    return (Vec);
}
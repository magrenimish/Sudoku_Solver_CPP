#include "Crop_Digits.h"

Mat processInput(Mat img)
{
    Mat img_gray, img_adpth;
    // convert to gray
    if (img.channels() == 3 || img.channels() == 4)
    {
        cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    }
    else
    {
        img_gray = img.clone();
    }
    // adaptive threshold
    adaptiveThreshold(img_gray, img_adpth, 255, 1, 1, 15, 10);
    return img_adpth;
}

cv::Mat trainOCR(cv::Mat& V) {
    bool r;
    Mat r1{};
    cv::Mat V1;

    //Process image to extract contour
    Mat img_src, img_gray, img_p, img_contours, mat_tmp;
    // load the file to train numbers
    img_src = V;
    // pre-process before getting the contours
    img_p = processInput(img_src);
    img_contours = img_p.clone();
    // find all the contours
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(img_contours, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
    // iterate through first hierarchy level contours
    //cout << "\n" << "contour size is " << contours.size() << "\n";
    for (int i = 0; i < contours.size(); i = hierarchy[i][0])
    {

        // find bounding rectangle
        //cout << "\n" << "contour is " << contours.at(i) << "\n";
        Rect rect = boundingRect(contours.at(i));
        /*cv::Rect myROI(rect.x, rect.y, rect.width, rect.height);
        cv::Mat croppedImage = img_src(myROI);
        imshow("new cropped image is ", croppedImage);
        waitKey(0);*/

        //const char* fname = filename.c_str();
        /*cout << "\n" << "x size is " << rect.x << "\n";
        cout << "\n" << "y size is " << rect.y << "\n";
        cout << "\n" << "width size is " << rect.width << "\n";
        cout << "\n" << "height size is " << rect.height << "\n";*/
        // reject too small rectangles in height
        if ((i == 0) && rect.height > 40 && rect.width > 40) { return(r1); break; }
        else if ((i == 0 && rect.height <= 9) || (i == 0 && rect.width <= 9)) { continue; }
        else if ((i == (contours.size() - 1)) && ((rect.height < 9 && rect.width>40))) { return(r1); break; }
        else if ((i == (contours.size() - 1)) && (rect.height > 40 && rect.width < 9)) { return(r1); break; }

        //else if ((i!=0 && rect.x==0) || (i!=0 &&rect.y==0)
        else if ((i != 0) && rect.height > 40 && rect.width > 40) { return(r1); break; }
        else if ((i != 0 && rect.height <= 9) || (i != 0 && rect.width <= 9)) continue;
        else if ((i == 0 && rect.height >= 40) || (i == 0 && rect.width >= 40)) { continue; }
        else if ((i != 0 && rect.height >= 40) || (i != 0 && rect.width >= 40)) continue;
        cv::Rect myROI(rect.x, rect.y, rect.width, rect.height);
        cv::Mat croppedImage = img_src(myROI);
        //imshow("new cropped image is ", croppedImage);
        //string img_name = std::to_string(i + 1) + ".jpg";
        //imwrite("C:/Users/nimis/source/repos/OpenCV_Course/OpenCV_Course/" + img_name, croppedImage);
        r = 1;
        r1 = croppedImage;
        V1 = r1;
        return(V1);
        //cout << "\n" << "V1 actual values are " << V1[0].first<<"\n";


    }

}


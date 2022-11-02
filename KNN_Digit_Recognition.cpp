#include "KNN_Digit_Recognition.h"
#include "dataset.h"

size_t K = 3;
uint32_t distSQ(size_t i, cv::Mat flat, size_t j) {
    uint32_t d = 0, z;
    for (size_t k = 0; k < 28 * 28; k++) {
        z = (uint32_t)flat.at<uchar>(k, 0) - (uint32_t)train_images[j][k];
        d += z * z;
    }
    return d;
}


uint8_t predict(size_t i, cv::Mat flat) {
    vector<pair<uint32_t, uint8_t>> D(train_labels.size());
    for (size_t j = 0; j < train_labels.size(); j++) {
        D[j] = { distSQ(i,flat, j), train_labels[j] };
    };
    sort(D.begin(), D.end());
    int F[10]{};
    for (size_t i = 0; i < min(K, D.size()); i++) {
        F[D[i].second] ++;
    }
    return max_element(F, F + 10) - F;
}

bool FileExists(string Filepath)
{
    struct stat buffer;
    return (stat(Filepath.c_str(), &buffer) == 0);
}


int * Prediction(vector<pair<bool, Mat>>& V) {
    //cout << "\n" << "V size is " << V.size() << "\n";
    static int pred[81];
    bool r;
    Mat r1;

    for (int a2 = 0; a2 < 3; a2++) {
        //cout << "\n" << "loop number " << a2 << "\n";
        for (int a1 = 0; a1 < 81; a1++) {
            r = V[a1].first;
            //cout << "\n" << "value of r is " << r << "\n";
            r1 = V[a1].second;
            
            if (a2 == 1 && (pred[a1] == 2 || pred[a1] == 3 || pred[a1] == 4 || pred[a1] == 5 || pred[a1] == 9)) continue;
            if (a2 == 2 && (pred[a1] == 2 || pred[a1] == 3 || pred[a1] == 4 || pred[a1] == 5 || pred[a1] == 8 || pred[a1] == 9 || pred[a1] == 6)) continue;
            //string path = "./hough_images/" + std::to_string(a1 + 1) + ".jpg";
            if (r == 1) {
                cv::Mat img = r1;
                cv::Mat padded;
                if (a2 == 0) {
                    cv::copyMakeBorder(img, padded, 9, 8, 12, 12, cv::BORDER_CONSTANT, cv::Scalar::all(255));
                }
                else if (a2 == 1) { cv::copyMakeBorder(img, padded, 10, 10, 10, 10, cv::BORDER_CONSTANT, cv::Scalar::all(255)); }
                else { cv::copyMakeBorder(img, padded, 5, 5, 5, 5, cv::BORDER_CONSTANT, cv::Scalar::all(255)); }
                Mat gray;
                if (padded.channels() == 1) { gray = padded; }
                else {
                    cvtColor(padded, gray, COLOR_BGR2GRAY);
                }
                for (int y = 0; y < gray.rows; y++)
                {
                    for (int z = 0; z < gray.cols; z++)
                    {
                        gray.at<uchar>(y, z) = 255 - gray.at<uchar>(y, z);
                    }
                }
                Mat resized_up;
                cv::resize(gray, resized_up, Size(28, 28), INTER_LINEAR);
                size_t C = 0;
                cv::Mat flat = resized_up.reshape(1, resized_up.total() * resized_up.channels());
                size_t c1 = predict(1, flat);
                if (a2 == 0) pred[a1] = c1;
                else if (a2 == 1 && c1 == 0) pred[a1] = 6;
                else if (a2 == 2 && c1 == 1) pred[a1] = 7;
                else if (a2 == 2 && c1 == 7) pred[a1] = 1;
            }
            else { pred[a1] = 0; continue; }
        }
    }
    return (pred);
}

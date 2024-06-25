/**
 * @file outOfFocusDeblur.cpp
 * @brief code for recovering out of focus image by Wiener filter
 */

#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace std;
using namespace cv;

void calcPSF(Mat& outputImg, Size filterSize, int R);
void fftshift(const Mat& inputImg, Mat& outputImg);
void filter2DFreq(const Mat& inputImg, Mat& outputImg, const Mat& H);
void calcWnrFilter(const Mat& input_h_PSF, Mat& output_G, double nsr);

const string keys =
    "{help h usage ? |                                         | print this message}"
    "{@input         | ./img/out_Of_Focus_Deblur_Original.jpg | input image}"
    "{R              | 5                                       | radius of Wiener filter}"
    "{SNR            | 100                                     | signal to noise ratio}"
;

int main(int argc, char** argv){

    Mat src, dst, Hw, h;

    CommandLineParser parser(argc, argv, keys);

    if (parser.has("help")){
        parser.printMessage();
        return 0;
    }

    int R = parser.get<int>("R");
    double SNR = parser.get<double>("SNR");

    //load image
    src = imread( parser.get<String>("@input"), IMREAD_COLOR );
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    //processing even images only
    Rect roi = Rect(0, 0, src.cols & -2, src.rows & -2);

    //H/W calculation starts
    calcPSF(h, roi.size(), R);
    calcWnrFilter(h, Hw, 1.0/SNR);

    //filtering starts
    filter2DFreq(src(roi), dst, Hw);

    dst.convertTo(dst, CV_8U);
    normalize(dst,dst,0,255,NORM_MINMAX);
    imshow("Original Image", src);
    imshow("Deblurred Image", dst);
    imwrite("Deblurred_Image.jpg", dst);
    waitKey(0);

    return 0;

}   


void calcPSF(Mat& outputImg, Size filterSize, int R)
{
    Mat h(filterSize, CV_32F, Scalar(0));
    Point point(filterSize.width / 2, filterSize.height / 2);
    circle(h, point, R, 255, -1, 8);
    Scalar summa = sum(h);
    outputImg = h / summa[0];
}


void fftshift(const Mat& inputImg, Mat& outputImg){
    outputImg = inputImg.clone();
    int cx = inputImg.cols/2;
    int cy = inputImg.rows/2;
    Mat q0(inputImg, Rect(0, 0, cx, cy));
    Mat q1(inputImg, Rect(cx, 0, cx, cy));
    Mat q2(inputImg, Rect(0, cy, cx, cy));
    Mat q3(inputImg, Rect(cx, cy, cx, cy));
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
}


void filter2DFreq(const Mat& inputImg, Mat& outputImg, const Mat& H){
    Mat planes[2] = {Mat_<float>(inputImg.clone()), Mat::zeros(inputImg.size(), CV_32F)};
    Mat complexImg;
    merge(planes, 2, complexImg);
    dft(complexImg, complexImg);

    Mat planesH[2] = {Mat_<float>(H.clone()), Mat::zeros(H.size(), CV_32F)};
    Mat complexH;
    merge(planesH, 2, complexH);
    Mat complexImgH;
    mulSpectrums(complexImg, complexH, complexImgH, 0);

    idft (complexImgH, complexImgH);
    split(complexImgH, planes);
    outputImg = planes[0];
    
}


void calcWnrFilter(const Mat& input_h_PSF, Mat& output_G, double nsr){
    Mat h_PSF_shifted;
    fftshift(input_h_PSF, h_PSF_shifted);
    Mat planes[2] = {Mat_<float>(h_PSF_shifted.clone()), Mat::zeros(h_PSF_shifted.size(), CV_32F)};
    Mat complexImg;
    merge(planes, 2, complexImg);
    dft(complexImg, complexImg);
    split(complexImg, planes);
    Mat denom;
    pow(abs(planes[0]), 2, denom);
    denom += nsr;
    divide(planes[0], denom, output_G);
}

/**
 * @file line_detectors.cpp
 * @brief code for extracting horizontal and vertical lines in an image
 */

#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace std;
using namespace cv;

Mat src, dst, src_gray, bw;

void show_wait_destroy(const char* winname, cv::Mat img) {
    imshow(winname, img);
    moveWindow(winname, 500, 0);
    waitKey(0);
    destroyWindow(winname);
}

int main(int argc, char** argv){

    //Load image
    CommandLineParser parser(argc, argv, "{@input | ./img/notes.jpg | input image}");;
    src = imread( parser.get<String>("@input"), IMREAD_COLOR );

    //checking image read error
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    // Show original image
    imshow("Original", src);

    //transform source image to grayscale id its not already
    if(src.channels() == 3){
        cvtColor(src, src_gray, COLOR_BGR2GRAY);
    }
    else{
        src_gray = src;
    }
    // Show grayscale image
    imshow("Gray", src_gray);

    // Apply adaptive threshold at the bitwise_not of src_gray, note the ~ symbol
    adaptiveThreshold(~src_gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);

    // Show binary image
    imshow("Binary", bw);

    //create the image that will use to extract horizontal and vertical lines
    Mat horizontal = bw.clone();
    Mat vertical = bw.clone();

    //specify the size of horizontal axis
    int horizontalSize = horizontal.cols / 30;
    //specify the size of vertical axis
    int verticalSize = vertical.rows / 30;


    //create structure element for extracting horizontal lines through morphology operations
    Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontalSize, 1));

    //apply morphology operations
    erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
    dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));

    //show extracted horizontal lines
    show_wait_destroy("Horizontal", horizontal);

    //create structure element for extracting vertical lines through morphology operations
    Mat verticalStructure = getStructuringElement(MORPH_RECT, Size(1, verticalSize));

    //apply morphology operations
    erode(vertical, vertical, verticalStructure, Point(-1, -1));
    dilate(vertical, vertical, verticalStructure, Point(-1, -1));

    //show extracted vertical lines
    show_wait_destroy("Vertical", vertical);

    // Inverse vertical image
    bitwise_not(vertical, vertical);
    show_wait_destroy("vertical_bit", vertical);

    // Extract edges and smooth image according to the logic
    // 1. extract edges
    // 2. dilate(edges)
    // 3. src.copyTo(smooth)
    // 4. blur smooth img
    // 5. smooth.copyTo(src, edges)

    // Step 1
    Mat edges;
    adaptiveThreshold(vertical, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, -2);
    show_wait_destroy("edges", edges);

    // Step 2
    Mat kernel = Mat::ones(2, 2, CV_8UC1);
    dilate(edges, edges, kernel);
    show_wait_destroy("dilate", edges);

    // Step 3
    Mat smooth;
    vertical.copyTo(smooth);

    // Step 4
    blur(smooth, smooth, Size(2, 2));

    // Step 5
    smooth.copyTo(vertical, edges);

    // Show final result
    show_wait_destroy("smooth - final", vertical);
    //! [smooth]

    return 0;


}
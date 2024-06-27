/**
 * @file morphologyOperations.cpp
 * @brief code for two very common morphological operators: Erosion and Dilation.
 */

#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace std;
using namespace cv;

//Global variables
Mat src, erosionDst, dilationDst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

//function to perform erosion
void Erosion(int, void*){
    int erosion_type = 0;
    
    if (erosion_elem == 0){erosion_type = MORPH_RECT;}
    else if (erosion_elem == 1){erosion_type = MORPH_CROSS;}
    else if (erosion_elem == 2) {erosion_type = MORPH_ELLIPSE;}

    Mat element = getStructuringElement(erosion_type,
                    Size(2*erosion_size + 1, 2*erosion_size+1),
                    Point(erosion_size, erosion_size));
    
    //erosion operation
    erode(src, erosionDst, element);
    imshow("Erosion Output", erosionDst);
}

//function to perform dilation
void Dilation(int, void*){
    int dilation_type = 0;
    
    if (dilation_elem == 0){dilation_type = MORPH_RECT;}
    else if (dilation_elem == 1){dilation_type = MORPH_CROSS;}
    else if (dilation_elem == 2 ) {dilation_type = MORPH_ELLIPSE;}

    Mat element = getStructuringElement( dilation_type,
                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                       Point( dilation_size, dilation_size ) ); 

    //dilation operation
    dilate(src, dilationDst, element);
    imshow("Dilation Output", dilationDst);

}

int main(int argc, char** argv){

    //Load image
    CommandLineParser parser(argc, argv, "{@input | ./img/mrph.jpg | input image}");
    // CommandLineParser parser(argc, argv, "{@input | ./img/morph.jpg | input image}");
    src = imread( parser.get<String>("@input"), IMREAD_COLOR );

    //checking image read error
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    //create erosion trackbar
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Output", &erosion_elem, max_elem, Erosion);
    createTrackbar("Kernel size:\n 2n +1", "Erosion Output", &erosion_size, max_kernel_size, Erosion);

    //create dilation trackbar
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Output", &dilation_elem, max_elem, Dilation);
    createTrackbar("Kernel size:\n 2n +1", "Dilation Output", &dilation_size, max_kernel_size, Dilation);

    // default start
    Erosion(0, 0);
    Dilation(0, 0);

    waitKey(0);
    imshow("Erosion Output", erosionDst);
    imshow("Dilation Output", dilationDst);
    return 0;

}

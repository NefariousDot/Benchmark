/*
* This tutorial demonstrates how to use OpenCV seamless cloning
* module without GUI.
*
* 1- Normal Cloning
* 2- Mixed Cloning
* 3- Monochrome Transfer
* 4- Color Change
* 5- Illumination change
* 6- Texture Flattening
*/

#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/photo.hpp"
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

void normalClone(const char* source, const char* destination, const char* mask);
void mixedClone(const char* source, const char* destination, const char* mask);
void monochromeTransfer(const char* source, const char* destination, const char* mask);
void color_Change(const char* source, const char* mask);
void illumination_Change(const char* source, const char* mask);
void texture_Flattening(const char* source, const char* mask);

int main(int argc, char** argv){

    cout << "NORMAL CLONING" << endl;
    normalClone("./img/NC_src.jpg", "./img/NC_dst.jpg", "./img/NC_mask.jpg");

    cout << "MIXED CLONING" << endl;
    mixedClone("./img/MC_src.jpg", "./img/MC_dst.jpg", "./img/MC_mask.jpg");

    cout << "MONOCHROME TRANSFER" << endl;
    monochromeTransfer("./img/MT_src.jpg", "./img/MT_dst.jpg", "./img/MT_mask.jpg");

    cout << "COLOR CHANGE" << endl;
    color_Change("./img/CC_src.jpg", "./img/CC_mask.jpg");

    cout << "ILLUMINATION CHANGE" << endl;
    illumination_Change("./img/IC_src.jpg", "./img/IC_mask.jpg");

    cout << "TEXTURE FLATTENING" << endl;
    texture_Flattening("./img/TF_src.jpg", "./img/TF_mask.jpg");

    return 0;
}

void normalClone(const char* source, const char* destination, const char* mask){

    Mat src = imread(source, IMREAD_COLOR);
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat dst = imread(destination, IMREAD_COLOR);
    if(dst.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat mask_ = imread(mask, IMREAD_COLOR);
    if(mask_.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat result;
    Point p;
    p.x = 400;
    p.y = 100;

    seamlessClone(src, dst, mask_, p, result, 1);
    imwrite("normal_clone.jpg", result);
    
}

void mixedClone(const char* source, const char* destination, const char* mask){

    Mat src = imread(source, IMREAD_COLOR);
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat dst = imread(destination, IMREAD_COLOR);
    if(dst.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }

    Mat mask_ = imread(mask, IMREAD_COLOR);
    if(mask_.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }

    Mat result;
    Point p;
    p.x = dst.size().width / 2;
    p.y = dst.size().height / 2;

    seamlessClone(src, dst, mask_, p, result, 2);
    imwrite("mixed_clone.jpg", result);
}

void monochromeTransfer(const char* source, const char* destination, const char* mask){

    Mat src = imread(source, IMREAD_COLOR);
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat dst = imread(destination, IMREAD_COLOR);
    if(dst.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }

    Mat mask_ = imread(mask, IMREAD_COLOR);
    if(mask_.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }

    Mat result;
    Point p;
    p.x = dst.size().width / 2;
    p.y = dst.size().height / 2;

    seamlessClone(src, dst, mask_, p, result, 3);
    imwrite("monochrome_transfer.jpg", result);


}

void color_Change(const char* source, const char* mask){

    Mat src = imread(source, IMREAD_COLOR);
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat mask_ = imread(mask, IMREAD_COLOR);
    if(mask_.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }

    Mat result;
    colorChange(src, mask_, result, 1.5, 0.5, 0.5);
    imwrite("color_change.jpg", result);

}

void illumination_Change(const char* source, const char* mask){

    Mat src = imread(source, IMREAD_COLOR);
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat mask_ = imread(mask, IMREAD_COLOR);
    if(mask_.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }

    Mat result;
    illuminationChange(src, mask_, result, 0.2f, 0.4f);
    imwrite("illumination_change.jpg", result);

}

void texture_Flattening(const char* source, const char* mask){

    Mat src = imread(source, IMREAD_COLOR);
    if(src.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }
    
    Mat mask_ = imread(mask, IMREAD_COLOR);
    if(mask_.empty()){
        cout << "Could not open or find the image" << endl;
        return;
    }

    Mat result;

    textureFlattening(src, mask_, result, 30, 45, 3);
    imwrite("texture_flattening.jpg", result);


}

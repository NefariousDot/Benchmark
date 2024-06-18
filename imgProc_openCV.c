#include <opencv2/opencv.hpp>
#include <time.h>

int main() {

    clock_t startAll, endAll;
    
    // Load the image
    cv::Mat inputImage = cv::imread("input5.png", cv::IMREAD_GRAYSCALE);
    if (inputImage.empty()) {
        printf("Could not open or find the image\n");
        return -1;
    }

    cv::Mat outputImage;

    // Measure and apply Gaussian Blur
    startAll = clock();
    clock_t startTime = clock();
    cv::GaussianBlur(inputImage, outputImage, cv::Size(3, 3), 0);
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken to apply Gaussian blur: %f seconds\n", timeTaken);
    cv::imwrite("output_gaussian_blur.png", outputImage);

    // Measure and apply Sobel Edge Detection
    startTime = clock();
    cv::Mat sobelX, sobelY, sobelOutput;
    cv::Sobel(inputImage, sobelX, CV_64F, 1, 0, 3);
    cv::Sobel(inputImage, sobelY, CV_64F, 0, 1, 3);
    cv::magnitude(sobelX, sobelY, sobelOutput);
    sobelOutput.convertTo(sobelOutput, CV_8U);
    endTime = clock();
    timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken for Sobel edge detection: %f seconds\n", timeTaken);
    cv::imwrite("output_sobel_edge.png", sobelOutput);

    // Measure and apply Image Rotation
    startTime = clock();
    cv::Point2f center(inputImage.cols / 2.0F, inputImage.rows / 2.0F);
    cv::Mat rotMatrix = cv::getRotationMatrix2D(center, 45, 1.0);
    cv::warpAffine(inputImage, outputImage, rotMatrix, inputImage.size());
    endTime = clock();
    timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken for image rotation: %f seconds\n", timeTaken);
    cv::imwrite("output_rotation.png", outputImage);

    // Measure and apply Histogram Equalization
    startTime = clock();
    cv::equalizeHist(inputImage, outputImage);
    endTime = clock();
    timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken for histogram equalization: %f seconds\n", timeTaken);
    cv::imwrite("output_equalized.png", outputImage);

    // Measure and apply Dilation
    startTime = clock();
    cv::Mat dilateKernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(inputImage, outputImage, dilateKernel);
    endTime = clock();
    timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken for dilation: %f seconds\n", timeTaken);
    cv::imwrite("output_dilation.png", outputImage);

    endAll = clock();
    timeTaken = ((double)(endAll - startAll)) / CLOCKS_PER_SEC;
    printf("\n\nTotal Execution time : %f seconds\n", timeTaken);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the Gaussian kernel (3x3 for simplicity)
const float gaussianKernel[3][3] = {
    {1.0/16, 2.0/16, 1.0/16},
    {2.0/16, 4.0/16, 2.0/16},
    {1.0/16, 2.0/16, 1.0/16}
};

// Function to apply Gaussian blur to a grayscale image
void applyGaussianBlur(unsigned char* inputImage, unsigned char* outputImage, int width, int height) {
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            float sum = 0.0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixel = inputImage[(y + ky) * width + (x + kx)];
                    sum += pixel * gaussianKernel[ky + 1][kx + 1];
                }
            }
            outputImage[y * width + x] = (unsigned char)sum;
        }
    }
}

// Function to apply Sobel edge detection
void applySobelEdgeDetection(unsigned char* inputImage, unsigned char* outputImage, int width, int height) {
    int sobelX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int sobelY[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            float gx = 0.0, gy = 0.0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixel = inputImage[(y + ky) * width + (x + kx)];
                    gx += pixel * sobelX[ky + 1][kx + 1];
                    gy += pixel * sobelY[ky + 1][kx + 1];
                }
            }
            int magnitude = (int)sqrt(gx * gx + gy * gy);
            outputImage[y * width + x] = (magnitude > 255) ? 255 : magnitude;
        }
    }
}

// Function to rotate image by 45 degrees
void rotateImage(unsigned char* inputImage, unsigned char* outputImage, int width, int height) {
    float angle = M_PI / 4.0; // 45 degrees in radians
    int centerX = width / 2;
    int centerY = height / 2;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int newX = (int)((x - centerX) * cos(angle) - (y - centerY) * sin(angle) + centerX);
            int newY = (int)((x - centerX) * sin(angle) + (y - centerY) * cos(angle) + centerY);

            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                outputImage[newY * width + newX] = inputImage[y * width + x];
            }
        }
    }
}

// Function to equalize histogram
void equalizeHistogram(unsigned char* inputImage, unsigned char* outputImage, int width, int height) {
    int histogram[256] = {0};
    int lut[256] = {0};
    int totalPixels = width * height;

    // Calculate histogram
    for (int i = 0; i < totalPixels; i++) {
        histogram[inputImage[i]]++;
    }

    // Calculate cumulative distribution function (CDF)
    int cdf = 0;
    for (int i = 0; i < 256; i++) {
        cdf += histogram[i];
        lut[i] = (int)((cdf * 255.0) / totalPixels);
    }

    // Apply equalization
    for (int i = 0; i < totalPixels; i++) {
        outputImage[i] = lut[inputImage[i]];
    }
}

// Function to apply dilation
void applyDilation(unsigned char* inputImage, unsigned char* outputImage, int width, int height) {
    int kernel[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int max = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixel = inputImage[(y + ky) * width + (x + kx)];
                    if (kernel[ky + 1][kx + 1] && pixel > max) {
                        max = pixel;
                    }
                }
            }
            outputImage[y * width + x] = max;
        }
    }
}

int main() {
    int width = 512; // Image width
    int height = 512; // Image height
    unsigned char* inputImage = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    unsigned char* outputImage = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    // Initialize the input image with some data (for simplicity, we'll use a constant value)
    for (int i = 0; i < width * height; i++) {
        inputImage[i] = 128; // Mid-gray value
    }

    // Measure the time taken to apply Gaussian blur
    clock_t startTime = clock();
    applyGaussianBlur(inputImage, outputImage, width, height);
    clock_t endTime = clock();
    printf("Time taken to apply Gaussian blur: %f seconds\n", ((double)(endTime - startTime)) / CLOCKS_PER_SEC);

    // Measure the time taken to apply Sobel edge detection
    startTime = clock();
    applySobelEdgeDetection(inputImage, outputImage, width, height);
    endTime = clock();
    printf("Time taken to apply Sobel edge detection: %f seconds\n", ((double)(endTime - startTime)) / CLOCKS_PER_SEC);

    // Measure the time taken to rotate the image
    startTime = clock();
    rotateImage(inputImage, outputImage, width, height);
    endTime = clock();
    printf("Time taken to rotate the image: %f seconds\n", ((double)(endTime - startTime)) / CLOCKS_PER_SEC);

    // Measure the time taken to equalize the histogram
    startTime = clock();
    equalizeHistogram(inputImage, outputImage, width, height);
    endTime = clock();
    printf("Time taken to equalize the histogram: %f seconds\n", ((double)(endTime - startTime)) / CLOCKS_PER_SEC);

    // Measure the time taken to apply dilation
    startTime = clock();
    applyDilation(inputImage, outputImage, width, height);
    endTime = clock();
    printf("Time taken to apply dilation: %f seconds\n", ((double)(endTime - startTime)) / CLOCKS_PER_SEC);

    // Free allocated memory
    free(inputImage);
    free(outputImage);

    return 0;
}

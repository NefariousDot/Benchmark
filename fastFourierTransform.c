#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>

#define PI 3.14159265358979323846

// FFT function to perform Fast Fourier Transform on array X of size n
void fft(complex double* X, int n) {
    if (n <= 1) return;// Base case: if the size is 1 or less, no need to process

    // Allocate memory for even and odd indexed elements
    complex double* even = (complex double*)malloc(n/2 * sizeof(complex double));
    complex double* odd = (complex double*)malloc(n/2 * sizeof(complex double));

    // Split the array into even and odd indexed elements
    for (int i = 0; i < n / 2; i++) {
        even[i] = X[i*2];
        odd[i] = X[i*2 + 1];
    }

    // Recursively call FFT on even and odd parts
    fft(even, n/2);
    fft(odd, n/2);

    // Combine the results from the even and odd parts
    for (int i = 0; i < n / 2; i++) {
        complex double t = cexp(-2.0 * I * PI * i / n) * odd[i];
        X[i] = even[i] + t;
        X[i + n/2] = even[i] - t;
    }

    // Free the allocated memory
    free(even);
    free(odd);
}

// Function to print the elements of a complex array X of size n
void print_array(complex double* X, int n) {
    for (int i = 0; i < n; i++) {
        printf("%2.2f + %2.2fi\n", creal(X[i]), cimag(X[i]));
    }
} 

//* Function to initialize an array X of size n with complex values
void initialize_array(complex double* X, int n) {
    for (int i = 0; i < n; i++) {
        X[i] = cos(2 * PI * i / n) + sin(2 * PI * i / n) * I;
    }
}

int main() {
    //int n = 8; // Must be a power of 2
    int n = 1 << 20; //* Set size of the array to 2^20 = 1048576 (must be a power of 2)
    
    // complex double X[] = {1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};
    complex double* X = (complex double*)malloc(n * sizeof(complex double)); //* Allocate memory for the array


    initialize_array(X, n); //* Initialize the array with complex values

    printf("Running FFT on an array of size %d\n", n);


    
    clock_t start, end;
    double runTime;

    // printf("Input:\n");
    // print_array(X, n);

    start = clock();  

    //* Measure the time taken for 10 FFT computations
    for (int i = 0; i < 10; i++) {
        fft(X, n); // Perform FFT on the array
    }

    end = clock();
    runTime = (double)(end - start) / CLOCKS_PER_SEC;

    // printf("Output:\n");
    // print_array(X, n);

    printf("\nExecution time: %f seconds\n", runTime);

    free(X); //* Free the allocated memory

    return 0;
}

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 100 // You can change this value for larger matrices

typedef long double ll;

void matrixMultiplication(ll a[N][N], ll b[N][N], ll result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    ll a[N][N], b[N][N], result[N][N];

    // Initialize matrices a and b with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 10001; //change the value to change the range and the size of the matrix
            b[i][j] = rand() % 10001; //change the value to change the range and the size of the matrix

            // Uncomment the following lines to generate random floating-point values
            // a[i][j] = ((double)rand() / RAND_MAX) * 100000.0; // Random floating-point values between 0 and 100000
            // b[i][j] = ((double)rand() / RAND_MAX) * 100000.0; // Random floating-point values between 0 and 100000

        }
    }

    // Perform matrix multiplication
    clock_t start = clock();
    matrixMultiplication(a, b, result);
    clock_t end = clock();

    // Calculate the execution time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the result matrix
    printf("Result matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%Lf ", result[i][j]);
        }
        printf("\n");
    }

    printf("\n\n#####################################################################\n");
    printf("Time taken for matrix multiplication: %f seconds\n", time_taken);
    printf("#####################################################################\n\n");

    return 0;
}

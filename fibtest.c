#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate Fibonacci
static long long int fibRun(long long int n) {
    if (n <= 1) return n;
    long long int a = 0, b = 1, c;
    for (long long int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Function to measure execution time
static double runTime(long long int n) {
    clock_t start = clock();
    printf("calculating %lld th fibonacci number.........\n", n);
    fibRun(n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    long long int n;
    printf("Input n: ");
    scanf("%lld", &n);
    printf("Execution time: %f seconds\n", runTime(n));
    return 0;
}
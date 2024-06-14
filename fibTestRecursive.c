#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Define a large enough size for memoization
#define MAX_FIB 7000000

// Memoization array to store Fibonacci values
uint64_t memo[MAX_FIB] = {0};

// Function to calculate Fibonacci using memoization
long long fibonacci(long long n) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to measure execution time
double measure_execution_time(long long n) {
    clock_t start, end;
    start = clock();
    long long result = fibonacci(n);
    //printf("Fibonacci(%u) = %lu\n", n, result);
    end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nFibonacci(%lld) = %lld\n", n, result);
    return time_taken;
}

// Function to measure memory usage
void measure_memory_usage() {
   uint32_t used_memory = 0;
   for (uint32_t i = 0; i < MAX_FIB; i++) {
       if (memo[i] != 0) {
           used_memory += sizeof(memo[i]);
       }
   }
   printf("Approximate memory usage: %u bytes\n", used_memory);
}

int main() {
    // Clear the memoization array
    memset(memo, 0, sizeof(memo));
    
    // Calculate Fibonacci numbers and measure performance
    long long n;
    printf("Enter the number of terms: "); // You can change this value to test different numbers
    scanf("%lld",&n);
    double time_taken = measure_execution_time(n);
    printf("Execution time: %f seconds\n", time_taken);
    
    // Measure memory usage
    measure_memory_usage();

    return 0;
}

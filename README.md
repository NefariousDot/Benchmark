# Benchmark

 A total of Seven different benchmarks are used to test the performance of Embedded in this chapter. Each type of benchmarks has its unique focal point for testing.
 For example, some benchmarks only operate on variables whose data type is an integer, while others work on data whose data type is a floating-point number.
 All of them are written in C.

|          TEST           |    STATUS    |
| ------------------------| -------------|
| Fibonacci Sequence      | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Matrix Multiplication   | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Fast Fourier Transform  | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Image Process           | ![Static Badge](https://img.shields.io/badge/TBA-%20Inprogress-%20orange)|
| Coremark Pro            | ![Static Badge](https://img.shields.io/badge/TBA-%20Inprogress-%20orange)| 
| Passmark                | ![Static Badge](https://img.shields.io/badge/TBA-%20Inprogress-%20orange)|
| Geekbench               | ![Static Badge](https://img.shields.io/badge/TBA-%20Inprogress-%20orange)|

## Fibonacci Sequence

As one of the classic mathematical models, the Fibonacci sequence was discovered by the mathematician Leonardo Fibonacci. Specifically, it refers to a sequence like this 1, 1, 2, 3, 5, 8, 13, 21, 34... The sequence starts at term 3, and each term is equal to the sum of the previous two. And in mathematics, the Fibonacci sequence is recursively represented as

```
F (0) = 0,
F (1) = 1,
F (n) = F (n − 1) + F (n − 2)(n ≥ 2, n ∈ N )
```

It is defined as a critical number sequence used in modern physical chemistry and other fields.

Here we have added two methods of fibonacci testing, one with iteration approach on fib calculation and another with recursive calculation along with memorization. Memoization will store the results of Fibonacci calculations to avoid redundant work. For the recursive approach without memoization, the maximum feasible value of n is relatively small (around 40-50) due to the exponential time complexity and the risk of stack overflow.

Fibonacci testing is often used for embedded systems for several reasons:
> **1. Resource Constraints:**
> Embedded systems typically operate with limited resources, such as memory and processing power. Fibonacci sequence calculations can be implemented in a   simple and efficient manner, making them suitable for testing the performance and resource management of these systems.
>
> **2. Algorithm Complexity:**
> Calculating Fibonacci numbers can be done using various algorithms, ranging from simple recursive methods to more complex iterative or matrix exponentiation techniques. This variety allows developers to test the efficiency and correctness of different algorithm implementations within the constraints of the embedded system.
> 
> **3. Predictability:**
> The Fibonacci sequence is well-defined and predictable. This makes it easy to verify the correctness of an implementation. The expected outputs are known and can be used to validate that the system is performing calculations correctly.
>
> **4. Performance Benchmarking:**
> Due to the varying complexity of Fibonacci calculation methods, these algorithms can be used to benchmark the performance of an embedded system. This helps in assessing the system’s ability to handle computational tasks and in comparing different systems or configurations
>
> **5. Stress Testing:**
> Calculating large Fibonacci numbers can be computationally intensive and can serve as a stress test for the system. It helps in evaluating the system's behavior under high computational loads, such as checking for stability, overheating, or other performance bottlenecks.
>
> **6. Stack and Memory Usage:**
> Recursive implementations of the Fibonacci sequence can test the stack usage of an embedded system. This is particularly useful in environments where stack size is limited. It can help identify potential stack overflow issues and optimize memory usage.
>
> **7. Code Optimization:**
> Fibonacci sequence calculations can be optimized in various ways, such as using memoization or iterative methods. This allows developers to test and optimize code for performance and efficiency on the embedded platform.


## Matrix Multiplication

Matrix multiplication, is mainly used as a benchmark to realise the multiplication of two large matrices. The data used in this part are mostly in integer types, and the operation type involved is multiplication between vectors. There are also specific regulations when doing matrix multiplication. An mxn matrix is an array of mxn numbers arranged in m rows and n columns. It only makes sense if the number of columns of the first matrix and the number of rows of the second matrix are the same. The specific principle of matrix operation is shown in the following equation:

```
--                 --     --                 --     --                 --
| A11 A12 . . . A1n |     | B11 B12 . . . B1m |     | C11 C12 . . . C1m |    
| A21 A22 . . . A2n |     | B21 B22 . . . B2m |     | C21 C22 . . . C2m |
| .   .     .   .   |     | .   .     .   .   |     | .   .     .   .   |
| .   .     .   .   |  x  | .   .     .   .   | =   | .   .     .   .   |
| .   .     .   .   |     | .   .     .   .   |     | .   .     .   .   |
| Am1 Am2 . . . Amn |     | Bn1 Bn2 . . . Bnm |     | Cm1 Cm2 . . . Cmm |
--                --      --                 --     --                 --
```
According to this equation, the number of rows in the result matrix is equal to the number of rows of the first matrix, and the number of columns of the result matrix is similar to the number of columns of the second matrix. The
element of the m th row and the n th column of the product C is equal to the
sum of the products of the element of the m th row of the matrix A and the
corresponding element of the n th column of the matrix B. In order not to make
the dimension of the matrix problematic in this thesis, the size of the first and
second matrices are 800x800.

Here we are using rand() function to generate the element of matrix with range 10000. 
To make the matrix multiplication more complex while keeping the changes limited to value adjustment, 
you can consider the following modifications:

> **1. Increase matrix size:** 
> Increasing the size of the matrices will make the computation more complex due to the larger number of operations required.
> 
> **2. Higher Range of Values:** 
> Use a much larger range of random values to increase the complexity of calculations.
>
> **3. Floating-Point Numbers:**
> Use floating-point numbers instead of integers to increase the complexity of calculations.

#### Why We Need to Test the Matrix Multiplication Benchmark
Matrix multiplication is a common and computationally intensive operation that appears in many scientific, engineering, and data processing applications. Testing the matrix multiplication benchmark is important for several reasons:
> **1. Performance Evaluation:**
> Matrix multiplication is a good indicator of the overall performance of a system, including its CPU, memory bandwidth, and cache performance.
> 
> **2. Optimization:**
> It helps identify potential bottlenecks and areas for optimization in both hardware and software.
>
> **3. Comparative Analysis:** 
> It allows for comparing the performance of different systems or different configurations of the same system.
>
>**4. Real-world Relevance:**
> Many real-world applications, such as machine learning algorithms, graphics processing, and scientific simulations, rely heavily on matrix operations.
>

## Fast Fourier Transform

The Fast Fourier transform is a general term for eﬀicient and fast computing methods for computing discrete Fourier transform (DFT) using a computer,
referred to as FFT. The Fast Fourier Transform was proposed in 1965 by J.W.Cooley and T.W. Tukey

This algorithm plays a crucial role in the digital signal processing process. It is frequently used in the communication industry.Hence, this benchmark aims to evaluate 
how well the system performs when executing a quick Fourier transform algorithm.


The FFT algorithm used in this benchmark code is the **Cooley-Tukey algorithm**. The Cooley-Tukey algorithm is the most commonly used and well-known FFT algorithm.
It efficiently computes the discrete Fourier transform (DFT) of a sequence, or its inverse, by recursively breaking down a DFT of any composite size 
N = N1xN2 into many smaller DFTs of sizes N1 and N2, typically N1=2 (i.e., breaking it into halves).

#### Key Characteristics of the Cooley-Tukey Algorithm in the Code

> **1. Divide and Conquer:**  
> The algorithm recursively splits the DFT of the sequence into two smaller DFTs of the even-indexed and odd-indexed elements.
>
> **2. Recursive Computation:**
> The fft function calls itself recursively on the even and odd parts of the array.
>
> **3. Combining Results:** 
> The results of the smaller DFTs are combined using complex exponentials (roots of unity), which involves computing twiddle factors (complex multipliers).
> 

#### Breakdown of the Algorithm in the Code

*step1 : Base case*

```c
if (n <= 1) return; // Base case: if the size is 1 or less, no need to process
```
+ The base case checks if the size of the array n is 1 or less. If it is, the function returns because a DFT of a single element is the element itself.

*Step 2: Splitting the Array*
```c
complex double* even = (complex double*)malloc(n / 2 * sizeof(complex double));
complex double* odd = (complex double*)malloc(n / 2 * sizeof(complex double));

for (int i = 0; i < n / 2; i++) {
    even[i] = X[i * 2];
    odd[i] = X[i * 2 + 1];
}
```
+ The input array X is split into two arrays: even and odd, containing the even-indexed and odd-indexed elements of X, respectively.

*Step 3: Recursive FFT Calls*
```c
fft(even, n / 2);
fft(odd, n / 2);
```
+ The fft function is called recursively on the even and odd arrays, effectively breaking down the problem into smaller subproblems.

*Step 4: Combining the Results*
```c
for (int i = 0; i < n / 2; i++) {
    complex double t = cexp(-2.0 * I * PI * i / n) * odd[i];
    X[i] = even[i] + t;
    X[i + n / 2] = even[i] - t;
}
```
+ The results of the smaller FFTs (even and odd) are combined to form the final result. This involves multiplying the elements of the odd array by complex exponentials (twiddle factors) and combining them with the even array elements.

*Step 5: Memory Management*
```c
free(even);
free(odd);
```
+ The dynamically allocated memory for the even and odd arrays is freed to prevent memory leaks.

This approach leverages the divide-and-conquer strategy to reduce the complexity of computing the DFT from 
O(N^2) to O(N log N), making the Cooley-Tukey algorithm highly efficient for large datasets.







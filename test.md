 #Fast Fourier Transform
 
 ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)

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



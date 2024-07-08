# Matrix Multiplication

![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)

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
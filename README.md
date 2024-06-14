# Benchmark

 A total of Seven different benchmarks are used to test the performance of Embedded in this chapter. Each type of benchmarks has its unique focal point for testing.For example, some benchmarks only operate on variables whose data type is an integer, while others work on data whose data type is a floating-point number.All of them are written in C.

|          TEST           |    STATUS    |
| ------------------------| -------------|
| Fibonacci Sequence      | Completed    |
| Matrix Multiplication   | Completed    |
| Fast Fourier Transform  | Completed    |
| Image Process           | Inprogress   |
| Coremark Pro            | Inprogress   | 
| Passmark                | Inprogress   |
| Geekbench               | Inprogress   |

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
> **1. Resource Constraints**
> Embedded systems typically operate with limited resources, such as memory and processing power. Fibonacci sequence calculations can be implemented in a   simple and efficient manner, making them suitable for testing the performance and resource management of these systems.
>
> **2. Algorithm Complexity**
> Calculating Fibonacci numbers can be done using various algorithms, ranging from simple recursive methods to more complex iterative or matrix exponentiation techniques. This variety allows developers to test the efficiency and correctness of different algorithm implementations within the constraints of the embedded system.
> 
> **3. Predictability**
> The Fibonacci sequence is well-defined and predictable. This makes it easy to verify the correctness of an implementation. The expected outputs are known and can be used to validate that the system is performing calculations correctly.
>
> **4. Performance Benchmarking**
> Due to the varying complexity of Fibonacci calculation methods, these algorithms can be used to benchmark the performance of an embedded system. This helps in assessing the system’s ability to handle computational tasks and in comparing different systems or configurations
>
> **5. Stress Testing**
> Calculating large Fibonacci numbers can be computationally intensive and can serve as a stress test for the system. It helps in evaluating the system's behavior under high computational loads, such as checking for stability, overheating, or other performance bottlenecks.
>
> **6. Stack and Memory Usage**
> Recursive implementations of the Fibonacci sequence can test the stack usage of an embedded system. This is particularly useful in environments where stack size is limited. It can help identify potential stack overflow issues and optimize memory usage.
>
> **7. Code Optimization**
> Fibonacci sequence calculations can be optimized in various ways, such as using memoization or iterative methods. This allows developers to test and optimize code for performance and efficiency on the embedded platform.


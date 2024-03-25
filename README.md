1.) Comparative execution time and short analysis of the performance of the kernels
Answer: 
This project focuses on the performance of dot product calculations between two vectors in C and x86-64 assembly, focusing on vector sizes of 2^20, 2^24, and 2^29 elements and comparing Debug and Release modes. We compared the time it takes to do these calculations in two different settings: Debug mode, where the code is easier to check for errors but runs slower, and Release mode, where the code runs faster because of extra tuning by the compiler.

Firstly, in debug mode, the performance difference between the C and assembly are minimal, which implies that the extra time it takes just to get the calculation started might hide how fast the computation is done. However, as vector sizes increase, assembly demonstrates a clear advantage in Debug mode, highlighting its potential for optimizing data processing tasks through direct hardware interaction. On the other hand, in release mode, where the compiler makes the code as efficient as possible, the C version starts to beat the assembly version, especially at larger vector sizes. This highlights the impact of compiler optimizations, such as effective SIMD utilization, making optimized C code significantly more efficient for parallelizable operations like the dot product. In conclusion, the results show that while writing code in assembly can be helpful in specific situations, using C with compiler optimizations turned on is generally the better choice for making fast and efficient programs, especially for large tasks.

2.) Take a screenshot of the program output with the correctness check (C).
3.) Take a screenshot of the program output, including the correctness check (x86-64).  
Answer for 2-3: 
![MP2-CorrectnessCheck](https://github.com/kenwin728/LBYARCH-MP/assets/114456221/49a62657-b3c0-4ba6-b13e-7411e3e3e49b)

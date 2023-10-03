# CS 616: High Performance Computing

## Assignment 2: Fun with OpenMP

### Description

- The objective of this assignment is to familiarize students with the practical application of OpenMP for parallelizing computational tasks
- Students will implement and optimize parallel
  algorithms for matrix operations
  - matrix multiplication
  - matrix transposition

### Requirements

- Matrix Multiplication
  - Implement a serial version of matrix multiplication
  - Then proceed to parallelize
    the matrix multiplication algorithm using OpenMP
  - Experiment with different
    numbers of threads and scheduling strategies
  - Analyze and report the speedup
    achieved with parallelization compared to the serial version
  - hint: use the chrono
    start/end code from the samples we demonstrated in class
- Matrix Transpostion
  - Implement a serial version of matrix transposition
  - Then proceed to parallelize
    the matrix transposition algorithm using OpenMP
  - Make sure to handle race
    conditions and ensure that the parallel version produces correct results
  - Analyze
    and report the speedup achieved with parallelization compared to the serial
    version

### Performance Analysis

- For both matrix multiplication and transposition, perform a performance analysis. Do this by
  testing by changing the matrix sizes and the number of threads
- Plot graphs (Excel or Google
  Sheets) showing execution time (serial vs. parallel), speedup and efficiency for different
  scenarios
- Discuss the impact of workload distribution and scheduling on performance.

### Deliverables

- Write a report documenting your implementation, experiments, and findings
- Discuss any challenges encountered and how they were addressed
- Make sure to include your graphs, source code, and any other relevant material in the report.

### Contributors

- Ponthea Zahraii
  - 2366637
  - zahraii@chapman.edu

### Files

- matrix_mult.cpp
- matrix_trans.cpp

### Execution Instructions

- Matrix Multiplication
  - g++ matrix_mult.cpp -o matrix_mult.exe
  - ./matrix_mult.exe
- Matrix Transposition
  - g++ matrix_trans.cpp -o matrix_trans.exe
  - ./matrix_trans.exe

### Workcited

- [Dartmouth](https://www.dartmouth.edu/~rc/classes/intro_openmp/openmp_functions.html)
- Course Material 
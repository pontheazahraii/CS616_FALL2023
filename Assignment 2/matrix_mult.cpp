#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

void serialMult(int N){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> mat1(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> mat2(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    // Serial matrix multiplication
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Output the elapsed time
    std::cout << "Time taken by function: " << duration/1000000.0 << " seconds" << std::endl;
}

void parallelMult(int N, int threads){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> mat1(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> mat2(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    // Set the number of threads
    // Citation - Dartmouth 
    omp_set_num_threads(threads);

    // Parallel matrix multiplication
    #pragma omp parallel for 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Output the elapsed time
    std::cout << "Time taken by function: " << duration/1000000.0 << " seconds" << std::endl;
}

//matrix multiplcation
int main() {
    // serial multiplcation
    serialMult(10); 
    serialMult(50); 
    serialMult(100);
    serialMult(500); 

    //parallel multiplcation
    // 2 threads 
    parallelMult(10, 2); 
    parallelMult(50, 2); 
    parallelMult(100, 2);
    parallelMult(500, 2);  

    // 4 threads 
    parallelMult(10, 4); 
    parallelMult(50, 4);
    parallelMult(100, 4); 
    parallelMult(500, 4); 

    // 6 threads 
    parallelMult(10, 6); 
    parallelMult(50, 6);
    parallelMult(100, 6); 
    parallelMult(500, 6); 

    // 8 threads 
    parallelMult(10, 8); 
    parallelMult(50, 8);
    parallelMult(100, 8); 
    parallelMult(500, 8); 

    // 10 threads 
    parallelMult(10, 10); 
    parallelMult(50, 10);
    parallelMult(100, 10); 
    parallelMult(500, 10); 


    return 0;
}

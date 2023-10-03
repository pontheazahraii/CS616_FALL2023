#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

void serialTrans(int N){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> mat1(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    // Serial matrix transposition
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[j][i] = mat1[i][j]; 
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Output the elapsed time
    std::cout << "Time taken by function: " << duration/1000000.0 << " seconds" << std::endl;
}

void parallelTrans(int N, int threads){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> mat1(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    // Set the number of threads
    // Citation - Dartmouth 
    omp_set_num_threads(threads);

    // Parallel matrix transposition
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[j][i] = mat1[i][j]; 
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Output the elapsed time
    std::cout << "Time taken by function: " << duration/1000000.0 << " seconds" << std::endl;
}

//matrix multiplcation
int main() {
    // serial transposition
    serialTrans(10); 
    serialTrans(50); 
    serialTrans(100);
    serialTrans(500); 

    //parallel transposition
    // 2 threads 
    parallelTrans(10, 2); 
    parallelTrans(50, 2); 
    parallelTrans(100, 2);
    parallelTrans(500, 2);  

    // 4 threads 
    parallelTrans(10, 4); 
    parallelTrans(50, 4);
    parallelTrans(100, 4); 
    parallelTrans(500, 4); 

    // 6 threads 
    parallelTrans(10, 6); 
    parallelTrans(50, 6);
    parallelTrans(100, 6); 
    parallelTrans(500, 6); 

    // 8 threads 
    parallelTrans(10, 8); 
    parallelTrans(50, 8);
    parallelTrans(100, 8); 
    parallelTrans(500, 8); 

    // 10 threads 
    parallelTrans(10, 10); 
    parallelTrans(50, 10);
    parallelTrans(100, 10); 
    parallelTrans(500, 10); 

    return 0;
}

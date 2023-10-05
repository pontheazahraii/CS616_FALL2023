# # CS 616: High Performance Computing

## Assignment 2: Fun with OpenMP

### Implementation
The implementation of the code was very simple. I was able to use the course resources and slightly modify the serial matrix multiplication code that we were given so that I could create two functions, one for serial multiplication and the other for parallel multiplication where the user gets to choose the dimension of an NxN matrix with the number of threads that they want to use for the parallelization of the matrix multiplication. For the matrix transposition, I went ahead and slightly modified the matrix multiplication code that I had created in order to perfrom matrix transposition. 

### Experiments
I decided that I want to experiement with an even number of threads going up to 10. I also decided that I want to create varying sized matrices with the greatest being a 500x500 matrix and the smallest being a 10x10. My machine only has 4 cores so I thought it would be interesting to experiment with threads above and below the number 4. I wanted to see if there would be a significant difference in the speed of the threads above 4. 

### Findings
What I found was that for the simple 10x10 matrix, running the program in serial was actually more effective. I suspect this is because a 10x10 matrix is a very simple problem to solve and so making it in parallel actually causes it to be more complex and thats why the serial had the best performance. Another thing I noticed was that the 4 threads did the best while the threads above 4 all had similar performance to one another suggesting that once all the best performance will occur when the same number of threads as processors is being used as the performance increase is not linear to the number of threads. 
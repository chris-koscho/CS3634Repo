#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv)
{

  //gcc -fopenmp -o ParallelHelloWorld ParallelHelloWorld.c

  //num_threads(3) clause will make our code run with 3 threads/cores, even if we have 4 allocated.
  //parallel clause alone will make the code run 4 times because it searches the computer for the number of allocated cores
  //num_threads(5) clause will make our code run with 5 threads
  #pragma omp parallel
  {
    //printf("helloworld\n");
    int rank = omp_get_thread_num();

    int size = omp_get_num_threads();

    printf("helloworld from OpenMP thread %d out of %d\n", rank, size);
  } 

  //if we compiled and ran our code, it would run 4 times. The virtual box has 4 cores, so that's why.

}


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>


int main() {

  int a[10];
  omp_set_num_threads(10);
  #pragma omp parallel
  {
    a[omp_get_thread_num()] = rand() % 10;
    #pragma omp barrrier

    #pragma omp for ordered // ordered 必须使用 parallel for
    for(int i = 0; i < 10; i++) 
    {
      #pragma omp ordered
      printf("a[%d] = %d\n", omp_get_thread_num(), a[omp_get_thread_num()]);
      
    }
  }
  return 0;
}
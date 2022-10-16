

#include <stdio.h>
#include <omp.h>


int main() {

  omp_set_num_threads(5);
  int i, j;
  #pragma omp parallel for private(i, j) collapse(2)
  for(i = 0; i < 2; i++) 
  {
    for(j = 0; j < 5; j++) 
    {
      printf("i = %d j = %d tid = %d\n", i, j ,omp_get_thread_num());
    }
  }
  return 0;
}
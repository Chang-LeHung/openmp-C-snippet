
#include <stdio.h>
#include <omp.h>
#include <unistd.h>


int main() {
  int n = 10;
  omp_set_num_threads(2);
  #pragma omp parallel
  {
    #pragma omp single
    {
      #pragma omp task if(n > 10)
      {
        sleep(1);
        printf("task 1\n");
      }

      #pragma omp task
      {
        sleep(1);
        printf("task 2\n");
      }
    }
  }

  return 0;
}

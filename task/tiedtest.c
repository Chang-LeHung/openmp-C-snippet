
#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  omp_set_num_threads(2);
  #pragma omp parallel
  {
    #pragma omp single
    {
      #pragma omp task
      {
        for (size_t i = 0; i < 1000000; i++)
        {
          printf("tid = %d generated a task\n", omp_get_thread_num());
          #pragma omp task
          {
            sleep(2);
            printf("tid = %d i = %ld\n", omp_get_thread_num(), i);
          }
        }
      }
    }
  }
  return 0;
}

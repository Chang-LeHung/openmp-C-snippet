
#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main() {

  omp_set_num_threads(1);
  #pragma omp parallel
  {
    #pragma omp single
    {
      #pragma omp task
      {
        for (size_t i = 0; i < 10; i++)
        {
          #pragma omp task
          {
            sleep(1);
            printf("tid = %d i = %ld\n", omp_get_thread_num(), i);
          }
        }
        printf("Hello World\n");
      }
    }
  }
  return 0;
}
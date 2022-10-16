

#include <stdio.h>
#include <omp.h>
#include <unistd.h>


int main() {

  #pragma omp parallel num_threads(5)
  {
    #pragma omp task untied
    {
      for(int i = 0; i < 10; i++) {
        sleep(1);
        printf("tid = %d i = %d\n", omp_get_thread_num(), i);
      }
    }
  }
  return 0;
}
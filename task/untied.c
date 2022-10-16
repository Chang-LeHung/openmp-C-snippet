

#include <stdio.h>
#include <omp.h>
#include <unistd.h>


int main() {

  #pragma omp parallel num_threads(5)
  {
    sleep(1);
    #pragma omp single
    {
      #pragma omp task untied
      {
        sleep(1);
        printf("tid = %d 1\n", omp_get_thread_num());
        sleep(1);
        printf("tid = %d 2\n", omp_get_thread_num());
        sleep(1);
        printf("tid = %d 3\n", omp_get_thread_num());
        sleep(1);
        printf("tid = %d 4\n", omp_get_thread_num());
        sleep(1);
        printf("tid = %d 5\n", omp_get_thread_num());
        sleep(1);
        printf("tid = %d 6\n", omp_get_thread_num());
      }
    }
  }
  return 0;
}
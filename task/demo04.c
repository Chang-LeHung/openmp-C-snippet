

#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main() {

  omp_set_num_threads(2);
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      #pragma omp task
      {
        sleep(2);
        printf("Task 1 from thread id = %d\n", omp_get_thread_num());
      }
    }

    #pragma omp section
    {
      #pragma omp task
      {
        sleep(2);
        printf("Task 2 from thread id = %d\n", omp_get_thread_num());
      }
    }

    #pragma omp section
    {
      #pragma omp task
      {
        sleep(2);
        printf("Task 3 from thread id = %d\n", omp_get_thread_num());
      }
    }
  }
  printf("sections 1 finished~ num threads = %d\n", omp_get_num_threads());

  omp_set_num_threads(2);
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      #pragma omp task
      {
        sleep(2);
        printf("Task 1 from thread id = %d\n", omp_get_thread_num());
      }
    }

    #pragma omp section
    {
      #pragma omp task
      {
        sleep(2);
        printf("Task 2 from thread id = %d\n", omp_get_thread_num());
      }
    }

    #pragma omp section
    {
      #pragma omp task
      {
        sleep(2);
        printf("Task 3 from thread id = %d\n", omp_get_thread_num());
      }
    }
  }
  printf("sections 2 finished~ num threads = %d\n", omp_get_num_threads());
  return 0;
}

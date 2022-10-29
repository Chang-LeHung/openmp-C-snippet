

#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int gpid;

int main() {

  omp_set_num_threads(2);
  #pragma omp parallel
  {
    #pragma omp single
    {

      #pragma omp task
      {
        printf("finish task 1 && pid = %d\n", omp_get_thread_num());
      }

      #pragma omp task
      {
        printf("finish task 2 && pid = %d\n", omp_get_thread_num());
      }

      #pragma omp task shared(gpid) untied
      {
        #pragma omp critical
        {
          gpid = omp_get_thread_num();
          printf("gpid = %d\n", gpid);
        }
        while(gpid == omp_get_thread_num()) {
          sleep(1);
          printf("pid = %d yield\n", omp_get_thread_num());
          #pragma omp taskyield
        }
        printf("finish task 3 && pid = %d\n", omp_get_thread_num());
      }

      #pragma omp task shared(gpid)
      {
        printf("task 4 pid = %d\n", omp_get_thread_num());
        for(int i = 0; i < 3; i++) {
          sleep(1);
          printf("gpid = %d pid = %d\n", gpid, omp_get_thread_num());
        }
      }
    }
  }
  return 0;
}
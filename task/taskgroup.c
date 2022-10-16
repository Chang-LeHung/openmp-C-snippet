

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>


int main() {

  #pragma omp parallel num_threads(2)
  {
    #pragma omp taskgroup
    {
      printf("First task start\n");
      sleep(1);
      printf("First task end\n");

      #pragma omp task
      {
        printf("First child task start\n");
        sleep(1);
        printf("First child task end\n");

        #pragma omp task
        {
          printf("First grandchild task start\n");
          sleep(5);
          printf("First grandchild task end\n");
        }
      }
    }

    #pragma omp task
    {
      printf("Second task start\n");
      sleep(2);
      printf("Second task end\n");
    }
  }

  return 0;
}
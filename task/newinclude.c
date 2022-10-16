

#include <stdio.h>
#include <omp.h>
#include <unistd.h>


int main() {

  omp_set_num_threads(1);
  #pragma omp parallel
  {
    #pragma omp task
    {
      printf("task 1\n");
      #pragma omp task
      {
        printf("inner task\n");
        #pragma omp task
        {
          printf("subtask of 111\n");
          sleep(2);
          printf("subtask of 1\n");
        }
      }
      printf("starting sleeping \n");
      sleep(5);
      printf("finishing sleeping\n");
      printf("out of subtask \n");
    }

    #pragma omp task
    {
      printf("task2\n");
    }
    
  }
  return 0;
}
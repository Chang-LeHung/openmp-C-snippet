

#include <stdio.h>
#include <omp.h>
#include <unistd.h>


int main() {


  #pragma omp parallel num_threads(2)
  {
    printf("tid = %d starts sleep \n", omp_get_thread_num());
    #pragma omp task
    {
      printf("tid = %d in task start\n", omp_get_thread_num());
      sleep(1);
      printf("tid = %d in task end\n", omp_get_thread_num());
    }
    int i = 0;
    while (i < 100)
    {
      usleep(100);
      printf("Hello World1\n");
      i++;
    }
    
    printf("tid = %d ends sleep \n", omp_get_thread_num());
    i = 0;
    while (i < 100)
    {
      usleep(100);
      printf("Hello World2\n");
      i++;
    }
  }

  printf("time = %lf\n", omp_get_wtime());
  printf("time = %lf\n", omp_get_wtime());
  sleep(1);
  printf("time = %lf\n", omp_get_wtime());

  return 0;
}
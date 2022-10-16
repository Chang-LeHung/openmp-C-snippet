
#include <stdio.h>
#include <omp.h>

int main() {

  int data = 0;
  int flag = 0;
  #pragma omp parallel sections num_threads(2)
  {
    #pragma omp section
    {
      printf("tid = %d data = %d\n", omp_get_thread_num(), data);
      for (size_t i = 0; i < 10000; i++)
      {
        data++;
      }
      flag = 1;
      #pragma omp flush(flag)
    }

    #pragma omp section
    {
        while (!flag)
        {
          #pragma omp flush(flag)
        }
        printf("tid = %d data = %d\n", omp_get_thread_num(), data);
        data--;
        printf("tid = %d data = %d\n", omp_get_thread_num(), data);
    }
  } 
  return 0;
}

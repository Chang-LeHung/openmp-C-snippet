#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main() {
  omp_set_num_threads(5);
  #pragma omp parallel
  {
    #pragma omp single
    {
      #pragma omp taskloop num_tasks(5)
      for(int i = 0; i < 20; i++)
        printf(" %d hello from tid = %d\n", i, omp_get_thread_num());
    }
  }
  return 0;
}

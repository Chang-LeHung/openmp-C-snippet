

#include <stdio.h>
#include <omp.h>

static long data;

int main() {

  printf("Int 类型的最大值等于 %ld\n", __INT64_MAX__);
  #pragma omp parallel num_threads(2) reduction(min:data)
  {
    printf("data =\t\t     %ld tid = %d\n", data, omp_get_thread_num());
    if(omp_get_thread_num() == 0) {
      data = 10;
    }else if(omp_get_thread_num() == 1){
      data = 20;
    }
  }
  printf("data = %ld\n", data);
  return 0;
}


#include <stdio.h>
#include <omp.h>

static int data;

int main() {

  printf("Int 类型的最小值等于 %d\n", 0x80000000);
  #pragma omp parallel num_threads(2) reduction(max:data)
  {
    printf("data =\t\t     %d tid = %d\n", data, omp_get_thread_num());
    if(omp_get_thread_num() == 0) {
      data = 10;
    }else if(omp_get_thread_num() == 1){
      data = 20;
    }
  }
  printf("data = %d\n", data);
  return 0;
}
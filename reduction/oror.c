

#include <stdio.h>
#include <omp.h>

static int data = 100;

int main() {

  #pragma omp parallel num_threads(2) reduction(||:data)
  {
    printf("初始化值 : data = %d tid = %d\n", data, omp_get_thread_num());
    if(omp_get_thread_num() == 0) {
      data = 0;
    }else if(omp_get_thread_num() == 1){
      data = 0;
    }
  }
  printf("在主函数当中 : data = %d\n", data);
  return 0;
}
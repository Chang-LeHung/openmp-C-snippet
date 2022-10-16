

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define len 1000
#define num_thread 5

char data[len];
// 在计算机当中浮点数不满足结合律
int sum = 0;

int find_sum() {
  int my_id = omp_get_thread_num();
  int local_sum = 0;
  int size = len / num_thread;
  int start = my_id * size;
  int end = (my_id + 1) * size;
  for(int i = start; i < end; i++) {
    local_sum += (int)data[i];
  }
  printf("local sum = %d tid = %d\n", local_sum, omp_get_thread_num());
  return local_sum;
}

int main() {

  memset(data, 1, sizeof(data));
  // 线程初始化私有变量为0 如果是乘法的话 则私有话变量为1
  #pragma omp parallel num_threads(num_thread) reduction(+:sum)
  {
    printf("tid = %d sum = %d\n", omp_get_thread_num(), sum);
    int t = find_sum(); // openmp 在执行这个操作的时候会使用一个临时变量去存储数据最后将这些数据加起来
    printf("tid = %d sum = %d t = %d\n", omp_get_thread_num(), sum, t);
    sum = t;
  }
  printf("sum = %d\n", sum);
  return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void hello();

int main(int argc, char* argv[]) {
  if (argc != 2)
  {
    fprintf(stderr, "argc != 2\n");
    exit(EXIT_FAILURE);
  }

  #ifdef _OPENMP
    printf("defined\n");
  #else
    printf("undefined\n");
  #endif
  
  int nproc = atoi(argv[1]);
  #pragma omp parallel num_threads(nproc) // 同时启动 nproc 线程执行相同的代码
  hello();
  return 0;
}

void hello() {
  int myId = omp_get_thread_num();
  int limit = omp_get_thread_limit();
  int threadCount = omp_get_num_threads();
  printf("hello from %d of %d threads and thread limit = %d\n", myId, threadCount, limit);
}

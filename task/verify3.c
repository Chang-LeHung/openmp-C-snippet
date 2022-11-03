

#include <omp.h>
#include <stdio.h>
#include <sys/types.h>


#define COLOR_NORMAL "\033[0m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_GREY "\033[1;30m"

#define STACK_DEBUG printf("tid = %d"COLOR_RED" rsp = %lx"COLOR_NORMAL \
                            COLOR_GREEN" rbp = %lx"COLOR_NORMAL"\n", \
                            omp_get_thread_num(), rsp, rbp);

#define FIND_RSP_RBP \
        asm volatile(\
          "movq %%rbp, %0;"\
          "movq %%rsp, %1;"\
          :"=m"(rbp), "=m"(rsp)::\
        );
#define HLINE printf("===========================\n");
u_int64_t rsp;
u_int64_t rbp;
int main() {

  #pragma omp parallel num_threads(1)
  {
    FIND_RSP_RBP

    STACK_DEBUG
    printf("This is outside top\n");
    HLINE

    #pragma omp task
    {
      FIND_RSP_RBP

      STACK_DEBUG
      printf("This is task 1\n");
      HLINE
    }

    #pragma omp task
    {
      FIND_RSP_RBP

      STACK_DEBUG
      printf("This is task 2\n");
      HLINE
    }

    #pragma omp task
    {
      FIND_RSP_RBP

      STACK_DEBUG
      printf("This is task 3\n");
      HLINE
    }
    #pragma omp task
    {
      FIND_RSP_RBP

      STACK_DEBUG
      printf("This is task 4\n");
      HLINE
    }

    FIND_RSP_RBP

    STACK_DEBUG
    printf("This is outside down\n");
    HLINE
  }

  return 0;
}
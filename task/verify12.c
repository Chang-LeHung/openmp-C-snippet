


#include <stdio.h>
#include <omp.h>
#include <sys/types.h>

#define COLOR_NORMAL "\033[0m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_GREY "\033[1;30m"
#define COLOR_BLUE "\033[1;34m"

#define STACK_DEBUG printf("tid = %d"COLOR_RED" rsp = 0x%lx"COLOR_NORMAL \
                            COLOR_GREEN" rbp = 0x%lx"COLOR_BLUE" stack size = %ld bytes"COLOR_NORMAL"\n", \
                            omp_get_thread_num(), rsp, rbp, rbp - rsp);

#define FIND_RSP_RBP \
        asm volatile(\
          "movq %%rbp, %0;"\
          "movq %%rsp, %1;"\
          :"=m"(rbp), "=m"(rsp)::\
        );
#define HLINE printf("===========================\n");
u_int64_t rsp;
u_int64_t rbp;


int gtid;

int main() {

  omp_set_num_threads(1);
  #pragma omp parallel
  {
    FIND_RSP_RBP
    STACK_DEBUG
    printf("Up out single\n");
    #pragma omp single
    {
      FIND_RSP_RBP
      STACK_DEBUG
      printf("Up in single\n");
      #pragma omp task shared(gtid)
      {
        FIND_RSP_RBP
        STACK_DEBUG
        printf("Up in task\n");
      }
      FIND_RSP_RBP
      STACK_DEBUG
      printf("Up out task\n");
    }
    FIND_RSP_RBP
    STACK_DEBUG
    printf("Up out single\n");
  }
  return 0;
}
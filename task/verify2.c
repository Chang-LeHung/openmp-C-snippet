

#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdint.h>

#define COLOR_NORMAL "\033[0m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_GREY "\033[1;30m"
#define COLOR_BLUE "\033[1;34m"

#define STACK_DEBUG_WITH_DATA printf("tid = %d"COLOR_RED" rsp = %lx"COLOR_NORMAL \
                            COLOR_GREEN" rbp = %lx"COLOR_BLUE" data address = %p"COLOR_NORMAL"\n", \
                            omp_get_thread_num(), rsp, rbp, &data);


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
#define SPLIT_LINE printf(">>>>>>>>>>>>>>>>>>>>>>>>>\n");

int gpid;
int gcnt;
uint64_t rbp;
uint64_t rsp;

int main() {
  omp_set_num_threads(2);
  #pragma omp parallel
  {
    #pragma omp single
    {
      HLINE
    }
    
    #pragma omp critical
    {
      printf("at the beginning pid = %d\n", omp_get_thread_num());
      FIND_RSP_RBP
      STACK_DEBUG
    }

    #pragma omp barrier
    #pragma omp single
    {
      HLINE
    }
    #pragma omp single
    {
      #pragma omp task shared(gpid) untied
      {
        int data = 100;
        printf("task verify pid = %d\n", omp_get_thread_num());
        FIND_RSP_RBP
        STACK_DEBUG_WITH_DATA
        gpid = omp_get_thread_num();
        while(1) {
          SPLIT_LINE
          sleep(1);
          data--;
          printf("tid = %d yield data = %d\n", omp_get_thread_num(), data);
          FIND_RSP_RBP
          STACK_DEBUG_WITH_DATA
          gcnt++;
          if (gcnt >= 10) break;
          #pragma omp taskyield
        }
        FIND_RSP_RBP
        STACK_DEBUG_WITH_DATA
        HLINE
        printf("tid = %d yield data = %d\n", omp_get_thread_num(), data);
      }

    }
  }
  return 0;
}

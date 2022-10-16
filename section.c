#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	#pragma omp parallel sections num_threads(2)
  {
		#pragma omp section 
		{
			printf("Section 1 ThreadId = %d\n", omp_get_thread_num());
			sleep(5);
		}
		
		#pragma omp section
		printf("Section 2 ThreadId = %d\n", omp_get_thread_num());
		#pragma omp section
		printf("Section 3 ThreadId = %d\n", omp_get_thread_num());
		#pragma omp section
		printf("Section 4 ThreadId = %d\n", omp_get_thread_num());
	}
	printf("has finished\n");
	return 0;
}
/* OUTPUT */
/*
Section 1 ThreadId = 30
Section 2 ThreadId = 16
Section 4 ThreadId = 0
Section 3 ThreadId = 21
*/

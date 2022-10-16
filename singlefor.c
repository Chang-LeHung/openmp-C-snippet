#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
	#pragma omp parallel 
	{
	    int i;
		#pragma omp for
		for (i = 0; i < 50; i++)
			printf("i = %d tid = %d\n", i, omp_get_thread_num());
	}
	return 0;
}

/* OUTPUT */
/*
i = 3
i = 4
i = 1
i = 0
i = 2
*/

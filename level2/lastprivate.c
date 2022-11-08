
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int t = 20, i;
	#pragma omp parallel for num_threads(1) firstprivate(t), lastprivate(t)
	for (i = 0; i < 10; i++)
	{
		printf("t = %d\n", t);
		t += 1;
	}
	printf("outside t = %d\n", t);
	return 0;
}
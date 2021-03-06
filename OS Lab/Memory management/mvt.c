// Multiprogramming memory simulation with a variable number of tasks

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, const char * argv []) {

	int total_space;
	printf("Enter total memory space: ");
	scanf(" %d", &total_space);

	int block_size;
	printf("Enter block size: ");
	scanf(" %d", &block_size);

	int memories[100];
	int i = 0, k = 0, mem, totalmem = 0;
	char mander;

	do {	
		printf("Enter memory required for process %.2d: ", i+1);
		scanf(" %d", &mem);
		if (mem < total_space) {
			memories[k++] = mem;
			totalmem += mem;
			printf("Memory allocated for process %.2d\n", i+1);
			// total_space -= (ceil(((float)mem)/100) * block_size);
		} /* else {
			total_space -= mem;
		} */
		// HAVE TO FIGURE OUT HOW TO ALLOCATE BETWEEN SEPARATE TASKS
		total_space -= (ceil(((float)mem)/100) * block_size);
		printf("Continue (y/n): ");
		scanf(" %c", &mander);
		i++;
	} while (mander == 'y');

	printf("\nPROCESS\tMEMORY\n");
	for (i = 0; i < k; ++i) {
		printf("  %d\t%d\n", i+1, memories[i]);
	}

	printf("Total memory allocated = %d\n", totalmem);
	if (total_space < 0)
		printf("Total external fragmentation = %d\n\n", -total_space);

	return 0;

}
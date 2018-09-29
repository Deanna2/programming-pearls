
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Pass in a pointer to the intArray to be written, the number of ints in the array, and the name of the file you are saving into.
int writeToBinaryFile(unsigned int *intArray, int length, char * name)
{
	
	FILE * bin_ptr;	
	bin_ptr = fopen(name, "wb");
	if (!bin_ptr)
	{
		printf("Unable to open input.bin :(\n");
		return 0;
	}

	fwrite(intArray, sizeof(unsigned int), length, bin_ptr);
	fclose(bin_ptr);
	return 1;
}



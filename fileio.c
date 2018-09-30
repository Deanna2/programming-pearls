
#include <stdio.h>
#include <stdlib.h>

// Pass in a pointer to the intArray to be written, the number of ints in the array, and the name of the file you are saving into.
int writeToBinaryFile(unsigned int *intArray, int length, char * name)
{
	
	FILE * bin_ptr;	
	bin_ptr = fopen(name, "wb");
	if (!bin_ptr)
	{
		printf("Unable to open binary file :(\n");
		return 0;
	}

	fwrite(intArray, sizeof(unsigned int), length, bin_ptr);
	fclose(bin_ptr);
	return 1;
}

// Pass in a pointer to the intArray to be written, the number of ints in the array, and the name of the file you are saving into.
int writeToTextFile(unsigned int *intArray, int length, char * name)
{
	FILE * txt_ptr;	
	txt_ptr = fopen(name, "w");
	if (!txt_ptr)
	{
		printf("Unable to open text file :(\n");
		return 0;
	}

	char * totalString = (char *) malloc(11 * length);
	for (int i = 0; i < length; ++i)
	{
		sprintf(&totalString[i * 11], "%10d\n", intArray[i]);
	}
	
	fwrite(totalString, 11, length, txt_ptr);
	fclose(txt_ptr);
	return 1;
}



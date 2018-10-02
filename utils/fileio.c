
#include <stdio.h>
#include <stdlib.h>

// Writes the binary numbers read into the intArray that is passed in.
int readFromBinaryFile(unsigned int *intArray, int length, char * name)
{
	FILE * ptr_myfile;
	ptr_myfile = fopen(name, "rb");	
	printf("Attempting to read from binary file %s\n", name);
	if (!ptr_myfile)
	{
		printf("Unable to open %s\n", name);
		return 0;
	}

	fread(intArray, sizeof(unsigned int), length, ptr_myfile);
	fclose(ptr_myfile);
	return 1;
}

// Pass in a pointer to the intArray to be written, the number of ints in the array, and the name of the file you are saving into.
int writeToBinaryFile(unsigned int *intArray, int length, char * name)
{
	
	FILE * bin_ptr;	
	bin_ptr = fopen(name, "wb");
	if (!bin_ptr)
	{
		printf("Unable to open %s\n", name);
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
		printf("Unable to open %s\n", name);
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



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getByteArrayLength(int maximumValue);

char * getBitmapArray(unsigned int intArray, int size, int byteArrayLength);

int main()
{
	int size = 5000000;
	unsigned int *intArray = (unsigned int *) malloc(sizeof(unsigned int) * size);
	FILE * ptr_myfile;

	ptr_myfile=fopen("input.bin", "rb");
	if (!ptr_myfile)
	{
		printf("Unable to open file :(\n");
		return 1;
	}

	fread(intArray, sizeof(unsigned int), size, ptr_myfile);
	fclose(ptr_myfile);

	// Create the byte array
	unsigned int byteArrayLength = (10000000 / 8) + 1;
	char *byteArray = (char *) calloc(byteArrayLength, 1);

	for (int i = 0; i < size; ++i)
	{
		unsigned int value = intArray[i];
		int byteArrayIndex = value / 8;
		int byteArrayOffset = value % 8;
		char a = 1;
		a = a << (byteArrayOffset); // Values are stored backwards in individual char
		byteArray[byteArrayIndex] = byteArray[byteArrayIndex] | a;
	}

	free(intArray);

	unsigned int *orderedArray = (unsigned int *) malloc(sizeof(unsigned int) * size);

	unsigned int counter = 0;
	for (int i = 0; i < byteArrayLength; ++i)
	{
		char byte = byteArray[i];
		for (int j = 0; j < 8; ++j)
		{
			char a = 1;
			a = a << j;
			if (byte & a) {
				unsigned int value = i * 8 + j;
				orderedArray[counter] = value;
				++counter;
			}
		}
	}

	FILE * bin_ptr;
	bin_ptr = fopen("output.bin","wb");
	if (!bin_ptr)
	{
		printf("Unable to open output.bin :(\n");
		return 1;
	}

	fwrite(orderedArray, sizeof(unsigned int), size, bin_ptr);
	fclose(bin_ptr);

	FILE * txt_ptr;
	txt_ptr = fopen("output.txt", "w");
	if (!txt_ptr)
	{
		printf("Unable to open output.txt :(\n");
		return 1;
	}
	
	char * totalString = (char *) malloc(11 * size);
	for (int i = 0; i < size; ++i)
	{
		sprintf(&totalString[i * 11], "%10d\n", orderedArray[i]);
	}
	
	fwrite(totalString, 11, size, txt_ptr);
	fclose(txt_ptr);

	free(orderedArray);
	free(totalString);
	
	return 0;
}

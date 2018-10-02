#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../utils/bitmap.h"
#include "../utils/fileio.h"

int main()
{
		
	struct timeval begin, end;
	gettimeofday(&begin, NULL);	
	int size = 5000000;
	unsigned int *intArray = (unsigned int *) malloc(sizeof(unsigned int) * size);

	if (!readFromBinaryFile(intArray, size, "input.bin"))
	{
		return 1;
	}
	
	unsigned int byteArrayLength = getByteArrayLength(10000000);
	char *byteArray = getBitmapArray(intArray, size, byteArrayLength);
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

	if (!writeToBinaryFile(orderedArray, size, "output.bin")){
		return 1;
	}
	
	if (!writeToTextFile(orderedArray, size, "output.txt")){
		return 1;
	}

	free(orderedArray);
	
	gettimeofday(&end, NULL);
	double elapsedMicroseconds = (double)((end.tv_usec - begin.tv_usec) + 1000000 * (end.tv_sec - begin.tv_sec));
	double elapsedSeconds = elapsedMicroseconds / 1000000;
       	printf("The sort took %.4f seconds.\n", elapsedSeconds);	
	return 0;
}

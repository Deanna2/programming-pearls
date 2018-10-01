#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "fileio.h"

int randomNumber(int max) {
	return rand() % max;
}

int main()
{
	int size = 5000000;
	unsigned int *intArray = (unsigned int *) malloc(sizeof(unsigned int) * size * 2);
	
	for (int i = 0; i < size * 2; ++i)
	{
		intArray[i] = i;
	}

	srand(time(NULL));
	
	for (int i = 0; i < 150000000; ++i)
	{
		int rand1 = randomNumber(size * 2);
		int rand2 = randomNumber(size * 2);
		unsigned int temp = intArray[rand1];
		intArray[rand1] = intArray[rand2];
		intArray[rand2] = temp;
	}

	unsigned int *halfArray = (unsigned int *) malloc(sizeof(unsigned int) * size);
	memcpy(halfArray, intArray, sizeof(unsigned int) * size); // Copy first half of array into new array

	free(intArray);

	if (!writeToBinaryFile(halfArray, size, "input.bin"))
	{
		return 1;
	}

	if (!writeToTextFile(halfArray, size, "input.txt"))
	{
		return 1;
	}

	free(halfArray);

	return 0;
}

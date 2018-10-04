#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../utils/fileio.h"

int randomNumber(int max) {
	return rand() % max;
}

int main()
{
	int range = 9999999;
	int size = 5000000;
	unsigned int *intArray = (unsigned int *) malloc(sizeof(unsigned int) * size);
	char *byteArray = (char *) calloc(range, 1);
	
	srand(time(NULL));

	int counter = 0;
	while (counter < size)
	{
		int rand = randomNumber(range);
		if (!byteArray[rand])
		{
			byteArray[rand] = 1;
			intArray[counter] = rand + 1; // set value to 0 - range
			++counter;
		}
	}
	free(byteArray);
	
	if (!writeToBinaryFile(intArray, size, "input.bin"))
	{
		return 1;
	}

	if (!writeToTextFile(intArray, size, "input.txt"))
	{
		return 1;
	}
	printf("Successfully wrote to binary file and text file\n");
	free(intArray);
	return 0;
}

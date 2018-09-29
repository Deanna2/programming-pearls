#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int max) {
	return rand() % max;
}

int main()
{
	int size = 5000000;
	unsigned int *intArray = (unsigned int *) malloc(sizeof(unsigned int) * size * 2);
	FILE * bin_ptr;
	FILE * txt_ptr;

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

	bin_ptr = fopen("input.bin", "wb");
	if (!bin_ptr)
	{
		printf("Unable to open input.bin :(\n");
		return 1;
	}

	fwrite(halfArray, sizeof(unsigned int) * size, 1, bin_ptr);
	fclose(bin_ptr);

	txt_ptr = fopen("input.txt", "w");
	if (!txt_ptr)
	{
		printf("Unable to open input.txt :(\n");
		return 1;
	}
	
	char * totalString = (char *) malloc(11 * size);
	for (int i = 0; i < size; ++i)
	{
		sprintf(&totalString[i * 11], "%10d\n", halfArray[i]);
	}
	
	fwrite(totalString, 11, size, txt_ptr);
	fclose(txt_ptr);

	free(halfArray);

	return 0;
}

#include <stdlib.h>

// Calculates the byte array length. Length is based on how many different numbers need to be stored.
int getByteArrayLength(int maximumValue)
{
	return (maximumValue / 8) + 1;
}

// Pass in the int array, the length of the array, and the length of the byteArray.
char * getBitmapArray(unsigned int * intArray, int length, int byteArrayLength)
{
	char *byteArray = (char *) calloc(byteArrayLength, 1);
        for (int i = 0; i < length; ++i)
	{
		unsigned int value = intArray[i];
		int byteArrayIndex = value / 8;
		int byteArrayOffset = value % 8;
		char a = 1;
		a = a << (byteArrayOffset); // Values are stored backwards in individual char
		byteArray[byteArrayIndex] = byteArray[byteArrayIndex] | a;
        }
	return byteArray;
}
 

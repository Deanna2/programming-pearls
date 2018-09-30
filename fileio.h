#include <stdio.h>
#include <stdlib.h>

// Writes the binary numbers read into the intArray that is passed in.
int readFromBinaryFile(unsigned int *intArray, int length, char * name);

// Pass in a pointer to the intArray to be written, the number of ints in the array, and the name of the file you are saving into.
int writeToBinaryFile(unsigned int *intArray, int length, char * name);

// Pass in a pointer to the intArray to be written, the number of ints in the array, and the name of the file you are saving into.
int writeToTextFile(unsigned int *intArray, int length, char * name);


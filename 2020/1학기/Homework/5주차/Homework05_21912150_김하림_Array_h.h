/* Array.h */
#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM_DATA 1000

void genRandArray(int array[], int size);
void suffleArray(int array[], int size);
void printArraySample(int array[], int size, int line_size);
void fprintArraySample(FILE* fout, int array[], int size, int line_size);

#endif
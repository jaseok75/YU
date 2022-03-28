/* Array.h */
#define _CRT_SECURE_NO_WARNINGS
#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_ARRAY_SIZE 30000
#define MAX_NUM_DATA 100

void printArraySample(int array[], int size, int line_size);
void fprintArraySample(FILE* fout, int array[], int size, int line_size);
double sumArray(int array[], int size);
void genRandArray(int array[], int size);
void getArrayStatistics(int data_array[], int num_data);
void fgetArrayStatistics(FILE* fout, int data_array[], int num_data);
int* genBigRandArray(int size);

#endif
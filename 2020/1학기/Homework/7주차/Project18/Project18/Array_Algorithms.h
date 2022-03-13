/* Array_Algorithms.h */
#ifndef ARRAY_ALGORITHMS_H
#define ARRAY_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Array_Algorithms.h"
#define ITEMS_PER_LINE 10
#define NUM_SAMPLE_LINES 2
#define HQS_THRESHOLD 50

double average(const int x, const int y);	//call-by-value
void average(const int* px, const int* py, double* pavg);	//call-by-pointer
void average(const int x, const int y, double& avg);	//call-by-reference
void swap(int* px, int* py);	//call-by-pointer
void swap(int& x, int& y);	//call-by-reference
void genBigRandArray(int* mA, int size, int base);
void fprintBigArraySample(FILE* fout, int* mA, int size, int items_per_line, int num_sample_lines);
void getArrayStatistics(int* array, int size, int* pMin, int* pMax, double* pAvg, double* pVar, double* pStd_dev);
void hybrid_quick_selection_sort(int* bigRandArray, int size);
void _hybridQuickSelectionSort(int* bigRandArray, int size, int left, int right, int level);

#endif
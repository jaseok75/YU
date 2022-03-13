/* array_algorithms.cpp */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <math.h>
#include "Array_Algorithms.h"

double average(const int x, const int y)	//call-by-value
{
	double avg;

	avg = (x + y) / 2.0;	//평균 구하기

	return avg;
}

void average(const int* px, const int* py, double* pavg)	//call-by-pointer
{
	double avg;

	avg = (*px + *py) / 2.0;	//평균 구하기
}

void average(const int x, const int y, double& avg)	//call-by-reference
{
	double sum;

	sum = x + y;
	avg = sum / 2.0;	//평균 구하기
}

void swap(int* px, int* py)	//call-by-pointer, swap
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

void swap(int& x, int& y)	//call-by-reference, swap
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void genBigRandArray(int* mA, int size, int base)
{
	char* flag;	//for checking duplicated rand_data
	int count = 0;
	unsigned int u_int32 = 0, bigRand, bigRand_withOffset;

	flag = (char*)calloc(size, sizeof(char));

	while (count < size)
	{
		u_int32 = ((long)rand() << 15);	//큰 난수 생성
		u_int32 = u_int32 + rand();
		bigRand = u_int32 % size;

		if (flag[bigRand] == 1)	//난수 중복 방지
		{
			continue;
		}

		else   //배열에 난수 저장
		{
			flag[bigRand] = 1;
			bigRand_withOffset = bigRand + base;
			mA[count++] = bigRand_withOffset;
		}
	}
	free(flag);
}

void fprintBigArraySample(FILE* fout, int* mA, int size, int items_per_line, int num_sample_lines)
{
	int count = 0;

	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < items_per_line; j++)
		{
			if (count > size)
			{
				fprintf(fout, "\n");
				return;
			}

			fprintf(fout, "%10d\t", mA[count]);
			count++;
		}
		fprintf(fout, "\n");
	}

	if (count >= size)
		return;
	if (count < (size - items_per_line * num_sample_lines))
	{
		count = size - items_per_line * num_sample_lines;
		fprintf(fout, " ..... \n");
	}

	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < items_per_line; j++)
		{
			if (count > size)
			{
				printf("\n");
				return;
			}
			fprintf(fout, "%10d\t", mA[count]);
			count++;
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "\n");
}

// 통계자료 구하는 함수
void getArrayStatistics(int* array, int size, int* pMin, int* pMax, double* pAvg, double* pVar, double* pStd_dev)
{
	int data;
	double sum = 0.0, sq_diff_sum = 0.0, diff;

	*pMin = INT_MAX;
	*pMax = INT_MIN;

	for (int i = 0; i < size; i++)
	{
		data = array[i];

		if (data < *pMin)
			*pMin = data;	//최솟값 구하기
		if (data > * pMax)
			*pMax = data;	//최댓값 구하기

		sum += data;
	}

	*pAvg = sum / size;	//평균 구하기
	sq_diff_sum = 0.0;

	for (int i = 0; i < size; i++)
	{
		diff = array[i] - *pAvg;
		sq_diff_sum += diff * diff;
	}

	*pVar = sq_diff_sum / size;	//분산 구하기
	*pStd_dev = sqrt(*pVar);	//표준편차 구하기
}

void hybrid_quick_selection_sort(int* bigRandArray, int size)
{
	if (size < HQS_THRESHOLD)
	{
		int index_min;	//index of minimum element
		int minElement;	//value of the minimum element

		for (int round = 0; round < size - 1; round++)
		{
			index_min = round;
			minElement = bigRandArray[round];

			for (int j = round + 1; j < size; j++)
			{
				if (bigRandArray[j] < minElement)
				{
					index_min = j;
					minElement = bigRandArray[j];
				}
			}

			if (index_min != round) /* if smaller element was found swap */
			{
				/* swap bigRandArray[index_min] and bigRandArray[round] minElement already has bigRandArrau[index_min] */
				bigRandArray[index_min] = bigRandArray[round];
				bigRandArray[round] = minElement;
			}
		}
	}

	else
	{
		_hybridQuickSelectionSort(bigRandArray, size, 0, size - 1, 0);
	}
}

void _hybridQuickSelectionSort(int* bigRandArray, int size, int left, int right, int level)
{
	int pl;
	int pivotValue;	//pivot value
	int newPI;	//new pivot index
	int temp;

	if (left >= right)
	{
		return;
	}

	else if (left < right)
	{
		pl = (right + left) / 2;
	}

	pivotValue = bigRandArray[pl];

	temp = bigRandArray[pl];
	bigRandArray[pl] = bigRandArray[right];
	bigRandArray[right] = temp;	//Move pivot to end

	newPI = left;

	for (int i = left; i < (right - 1); i++)
	{
		if (bigRandArray[i] <= pivotValue)
		{
			temp = bigRandArray[i];
			bigRandArray[i] = bigRandArray[newPI];
			bigRandArray[newPI] = temp;

			newPI++;
		}
	}

	//swap bigRandArray[newPI] and array[right];	Move pivot to its final place
	temp = bigRandArray[newPI];
	bigRandArray[newPI] = bigRandArray[right];
	bigRandArray[right] = temp;

	if (left < (newPI - 1))
	{
		_hybridQuickSelectionSort(bigRandArray, size, left, newPI - 1, level + 1);	//재귀함수 호출
	}

	if ((newPI + 1) < right)
	{
		_hybridQuickSelectionSort(bigRandArray, size, newPI, right, level + 1);	//재귀함수 호출
	}
}
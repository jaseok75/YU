/**
 * 파일명: "PL05_21912150_김하림_Lab01_Array.cpp"
 * 프로그램의 목적 및 기본 기능:
 * - 이 프로그램은 배열에 랜덤 숫자를 넣고 통계자료를 산출하고,
 *   실행 화면과 파일에 출력하기 위한 프로그램을 만드는 데 필요한 함수들이다.
 *
 * 프로그램 작성자: 김하림 (2020년 04월 19일),
 * 최종 Update: 2020년 04월 19일 (김하림).
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Array.h"

void printArraySample(int array[], int size, int line_size)	//배열의 내용 출력 함수
{
	printf("Size of integer array = %d\n", size);

	if (size <= 50)	//배열의 크기가 50 이하일 때
	{
		for (int i = 0, count = 0; i < size; i++)	//배열을 한 줄에 10개씩 출력
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
			{
				printf("\n");
			}
		}
		printf("\n");
	}

	else   //배열의 크기가 50을 초과할 때
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//배열의 맨 첫 2줄 출력
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("....\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//배열의 맨 끝 2줄 출력
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("\n");
	}
}

void fprintArraySample(FILE* fout, int array[], int size, int line_size)	//배열의 내용을 파일에 출력하는 함수
{
	fprintf(fout, "Size of integer array = %d\n", size);

	if (size <= 50)	//배열의 크기가 50 이하일 때
	{
		for (int i = 0, count = 0; i < size; i++)	//배열을 한 줄에 10개씩 출력
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
			{
				fprintf(fout, "\n");
			}
		}
		fprintf(fout, "\n");
	}

	else   //배열의 크기가 50을 초과할 때
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//배열의 맨 첫 2줄 출력
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
			{
				fprintf(fout, "\n");
			}
		}
		fprintf(fout, "...\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//배열의 맨 끝 2줄 출력
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
			{
				fprintf(fout, "\n");
			}
		}
		fprintf(fout, "\n");
	}
}

double sumArray(int array[], int size)	//주어진 배열의 모든 원소들을 합산하여 double 자료형으로 반환
{
	double sum = 0.0;	//local variable

	for (int i = 0; i < size; i++)	//배열의 모든 원소 합산
	{
		sum += array[i];
	}

	return sum;	//return the result
}

void getArrayStatistics(int data_array[], int num_data)	//주어진 배열의 통계 정보 산출
{
	int data, min, max;
	double sum = 0.0, var, diff, sq_diff_sum = 0.0, avg, std_dev;

	min = INT_MAX;
	max = INT_MIN;

	for (int i = 0; i < num_data; i++)	//배열의 최댓값, 최솟값 찾기
	{
		data = data_array[i];

		if (data < min)
			min = data;
		if (data > max)
			max = data;
	}

	sum = sumArray(data_array, num_data);	//배열 원소들의 합산
	avg = sum / num_data;	//배열 원소의 평균
	sq_diff_sum = 0.0;

	for (int i = 0; i < num_data; i++)
	{
		diff = data_array[i] - avg;
		sq_diff_sum += diff * diff;
	}

	var = sq_diff_sum / num_data;	//배열 원소의 분산
	std_dev = sqrt(var);	//배열 원소의 표준편차
	printf("Total (%3d) integer data : \n", num_data);
	printArraySample(data_array, num_data, 10);
	printf("min (%3d), max (%3d), ", min, max);
	printf("sum (%8.2lf), average (%8.2lf), ", sum, avg);
	printf("variance (%8.2lf), standard deviation (%8.2lf)\n", var, std_dev);
}

void fgetArrayStatistics(FILE* fout, int data_array[], int num_data)	//주어진 배열의 통계 정보 산출
{
	int data, min, max;
	double sum = 0.0, var, diff, sq_diff_sum = 0.0, avg, std_dev;

	min = INT_MAX;
	max = INT_MIN;

	for (int i = 0; i < num_data; i++)	//배열 원소의 최댓값, 최솟값 계산
	{
		data = data_array[i];

		if (data < min)
			min = data;
		if (data > max)
			max = data;
	}

	sum = sumArray(data_array, num_data);	//배열 원소의 합
	avg = sum / num_data;	//배열 원소의 평균
	sq_diff_sum = 0.0;

	for (int i = 0; i < num_data; i++)
	{
		diff = data_array[i] - avg;
		sq_diff_sum += diff * diff;
	}

	var = sq_diff_sum / num_data;	//배열 원소의 분산
	std_dev = sqrt(var);	//배열 원소의 표준편차

	fprintf(fout, "Total (%3d) integer data : \n", num_data);
	fprintArraySample(fout, data_array, num_data, 10);
	fprintf(fout, "min (%3d), max (%3d), ", min, max);
	fprintf(fout, "sum (%8.2lf), average (%8.2lf), ", sum, avg);
	fprintf(fout, "variance (%8.2lf), standard deviation (%8.2lf)\n", var, std_dev);
}

void genRandArray(int array[], int size)	//30000이하의 중복되지 않는 난수 생성 후 배열에 저장
{
	int d;
	char flag[MAX_ARRAY_SIZE] = { 0 };

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++)
	{
		d = rand() % size;

		while (flag[d] == 1)	//while d was generated before, try new one
			d = rand() % size;

		flag[d] = 1;	//mark d as generated
		array[i] = d;
	}
}

int* genBigRandArray(int size)	//30000을 초과하는 중복되지 않는 난수 생성 후 배열에 저장
{
	int* flag = 0;
	int count = 0;
	unsigned int uint_32;
	unsigned int random_number = 0;
	int* bonus_array = 0;

	srand((unsigned)time(NULL));
	flag = (int*)malloc(sizeof(int) * size);	//flag 포인터 동적 할당
	bonus_array = (int*)malloc(sizeof(int) * size);	//bonus_array 포인터 동적 할당

	while (count < size)
	{
		uint_32 = ((long)rand() << 15) | rand();	//RAND_MAX를 초과하는 랜덤 숫자 생성
		random_number = uint_32 % size;	//생성된 랜덤 숫자 중 일부를 랜덤 숫자로 저장

		if (flag[random_number] == 1)	//while d was generated before, try new one
			continue;
		else   //mark d as generated
		{
			flag[random_number] = 1;
			bonus_array[count++] = random_number;
		}
	}

	return bonus_array;	//bonus_array 반환
}
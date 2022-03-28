/**
 * ���ϸ�: "PL05_21912150_���ϸ�_Lab01_Array.cpp"
 * ���α׷��� ���� �� �⺻ ���:
 * - �� ���α׷��� �迭�� ���� ���ڸ� �ְ� ����ڷḦ �����ϰ�,
 *   ���� ȭ��� ���Ͽ� ����ϱ� ���� ���α׷��� ����� �� �ʿ��� �Լ����̴�.
 *
 * ���α׷� �ۼ���: ���ϸ� (2020�� 04�� 19��),
 * ���� Update: 2020�� 04�� 19�� (���ϸ�).
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Array.h"

void printArraySample(int array[], int size, int line_size)	//�迭�� ���� ��� �Լ�
{
	printf("Size of integer array = %d\n", size);

	if (size <= 50)	//�迭�� ũ�Ⱑ 50 ������ ��
	{
		for (int i = 0, count = 0; i < size; i++)	//�迭�� �� �ٿ� 10���� ���
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

	else   //�迭�� ũ�Ⱑ 50�� �ʰ��� ��
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//�迭�� �� ù 2�� ���
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("....\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//�迭�� �� �� 2�� ���
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("\n");
	}
}

void fprintArraySample(FILE* fout, int array[], int size, int line_size)	//�迭�� ������ ���Ͽ� ����ϴ� �Լ�
{
	fprintf(fout, "Size of integer array = %d\n", size);

	if (size <= 50)	//�迭�� ũ�Ⱑ 50 ������ ��
	{
		for (int i = 0, count = 0; i < size; i++)	//�迭�� �� �ٿ� 10���� ���
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

	else   //�迭�� ũ�Ⱑ 50�� �ʰ��� ��
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//�迭�� �� ù 2�� ���
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
			{
				fprintf(fout, "\n");
			}
		}
		fprintf(fout, "...\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//�迭�� �� �� 2�� ���
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

double sumArray(int array[], int size)	//�־��� �迭�� ��� ���ҵ��� �ջ��Ͽ� double �ڷ������� ��ȯ
{
	double sum = 0.0;	//local variable

	for (int i = 0; i < size; i++)	//�迭�� ��� ���� �ջ�
	{
		sum += array[i];
	}

	return sum;	//return the result
}

void getArrayStatistics(int data_array[], int num_data)	//�־��� �迭�� ��� ���� ����
{
	int data, min, max;
	double sum = 0.0, var, diff, sq_diff_sum = 0.0, avg, std_dev;

	min = INT_MAX;
	max = INT_MIN;

	for (int i = 0; i < num_data; i++)	//�迭�� �ִ�, �ּڰ� ã��
	{
		data = data_array[i];

		if (data < min)
			min = data;
		if (data > max)
			max = data;
	}

	sum = sumArray(data_array, num_data);	//�迭 ���ҵ��� �ջ�
	avg = sum / num_data;	//�迭 ������ ���
	sq_diff_sum = 0.0;

	for (int i = 0; i < num_data; i++)
	{
		diff = data_array[i] - avg;
		sq_diff_sum += diff * diff;
	}

	var = sq_diff_sum / num_data;	//�迭 ������ �л�
	std_dev = sqrt(var);	//�迭 ������ ǥ������
	printf("Total (%3d) integer data : \n", num_data);
	printArraySample(data_array, num_data, 10);
	printf("min (%3d), max (%3d), ", min, max);
	printf("sum (%8.2lf), average (%8.2lf), ", sum, avg);
	printf("variance (%8.2lf), standard deviation (%8.2lf)\n", var, std_dev);
}

void fgetArrayStatistics(FILE* fout, int data_array[], int num_data)	//�־��� �迭�� ��� ���� ����
{
	int data, min, max;
	double sum = 0.0, var, diff, sq_diff_sum = 0.0, avg, std_dev;

	min = INT_MAX;
	max = INT_MIN;

	for (int i = 0; i < num_data; i++)	//�迭 ������ �ִ�, �ּڰ� ���
	{
		data = data_array[i];

		if (data < min)
			min = data;
		if (data > max)
			max = data;
	}

	sum = sumArray(data_array, num_data);	//�迭 ������ ��
	avg = sum / num_data;	//�迭 ������ ���
	sq_diff_sum = 0.0;

	for (int i = 0; i < num_data; i++)
	{
		diff = data_array[i] - avg;
		sq_diff_sum += diff * diff;
	}

	var = sq_diff_sum / num_data;	//�迭 ������ �л�
	std_dev = sqrt(var);	//�迭 ������ ǥ������

	fprintf(fout, "Total (%3d) integer data : \n", num_data);
	fprintArraySample(fout, data_array, num_data, 10);
	fprintf(fout, "min (%3d), max (%3d), ", min, max);
	fprintf(fout, "sum (%8.2lf), average (%8.2lf), ", sum, avg);
	fprintf(fout, "variance (%8.2lf), standard deviation (%8.2lf)\n", var, std_dev);
}

void genRandArray(int array[], int size)	//30000������ �ߺ����� �ʴ� ���� ���� �� �迭�� ����
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

int* genBigRandArray(int size)	//30000�� �ʰ��ϴ� �ߺ����� �ʴ� ���� ���� �� �迭�� ����
{
	int* flag = 0;
	int count = 0;
	unsigned int uint_32;
	unsigned int random_number = 0;
	int* bonus_array = 0;

	srand((unsigned)time(NULL));
	flag = (int*)malloc(sizeof(int) * size);	//flag ������ ���� �Ҵ�
	bonus_array = (int*)malloc(sizeof(int) * size);	//bonus_array ������ ���� �Ҵ�

	while (count < size)
	{
		uint_32 = ((long)rand() << 15) | rand();	//RAND_MAX�� �ʰ��ϴ� ���� ���� ����
		random_number = uint_32 % size;	//������ ���� ���� �� �Ϻθ� ���� ���ڷ� ����

		if (flag[random_number] == 1)	//while d was generated before, try new one
			continue;
		else   //mark d as generated
		{
			flag[random_number] = 1;
			bonus_array[count++] = random_number;
		}
	}

	return bonus_array;	//bonus_array ��ȯ
}
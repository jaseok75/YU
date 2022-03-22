/* Two_Dim_Array_Operations.cpp */
#include <stdio.h> 
#include <stdlib.h> 
#include "Two_Dim_Array_Operations.h"

// �μ��� �޾ƿ� ũ�⸸ŭ ������ �迭 �����ϱ�
double** create2DimDoubleArray(int row_size, int col_size)
{
	double** ppDA;
	ppDA = (double**)calloc(row_size, sizeof(double*));	//�����Ҵ�
	for (int m = 0; m < row_size; m++)
	{
		ppDA[m] = (double*)calloc(col_size, sizeof(double)); //�����Ҵ�
	}

	return ppDA;
}

// ������ �迭�� ���� �Ҵ� �����ϴ� �Լ�
void delete2DimDoubleArray(double** dM, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(dM[r]);	//���� �Ҵ� ����
	}

	free(dM);	//���� �Ҵ� ����
}

// ���Ͽ��� ���ڸ� �о�� �迭�� �����ϴ� �Լ�
void fget2DimDoubleArray(FILE* fp, double** dM, int row_size, int col_size)
{
	double d = 0.0;

	//�޾ƿ� ������ �߸��� �����̶�� ����
	if (fp == NULL)
	{
		printf("Error in get2DimDoubleArray() -file pointer is NULL !!\n");
		exit(-1);
	}

	for (int m = 0; m < row_size; m++)
		for (int n = 0; n < col_size; n++)
		{
			if (fscanf(fp, "%lf", &d) != EOF) //���Ͽ��� ���ڸ� �о��
				dM[m][n] = d;	//�о�� ���ڸ� �迭�� ����
		}
}

// �迭�� ����ȭ�鿡 ����ϴ� �Լ�
void print2DimDoubleArray(double** mA, int row_size, int col_size)
{
	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			printf("%8.2lf", mA[m][n]);	//�迭�� ���
		}
		printf("\n");	//�ٹٲ�
	}
}

// �迭�� ���� ����� ���ϴ� �Լ�
double getRow_Avg(double** array, int row, int num_cols)
{
	double sum = 0.0, row_avg;

	for (int i = 0; i < num_cols; i++)
	{
		sum += array[row][i]; //�迭�� ���� ���ڸ� ��� ����
	}

	row_avg = sum / (double)num_cols;	//���� ���ڸ� �� ���� ũ��� ����(���)

	return row_avg;	//��� ��ȯ
}

//2���� �迭 ��ü ������ ����� ���ϴ� �Լ�
double getTotalAvg(double** array, int num_rows, int num_cols)
{
	double sum = 0.0, avg;

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			sum += array[r][c];	//�迭�� ��ü ���Ҹ� ��� �� ����
		}
	}

	avg = sum / (double)(num_rows * num_cols); //���� ���ڸ� �迭�� ũ��� ����(���)

	return avg;	//��� ��ȯ
}
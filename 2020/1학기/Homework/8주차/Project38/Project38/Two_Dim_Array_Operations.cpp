/* Two_Dim_Array_Operations.cpp */
#include <stdio.h> 
#include <stdlib.h> 
#include "Two_Dim_Array_Operations.h"

// 인수로 받아온 크기만큼 포인터 배열 생성하기
double** create2DimDoubleArray(int row_size, int col_size)
{
	double** ppDA;
	ppDA = (double**)calloc(row_size, sizeof(double*));	//동적할당
	for (int m = 0; m < row_size; m++)
	{
		ppDA[m] = (double*)calloc(col_size, sizeof(double)); //동적할당
	}

	return ppDA;
}

// 포인터 배열의 동적 할당 해제하는 함수
void delete2DimDoubleArray(double** dM, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(dM[r]);	//동적 할당 해제
	}

	free(dM);	//동적 할당 해제
}

// 파일에서 숫자를 읽어와 배열에 저장하는 함수
void fget2DimDoubleArray(FILE* fp, double** dM, int row_size, int col_size)
{
	double d = 0.0;

	//받아온 파일이 잘못된 파일이라면 중지
	if (fp == NULL)
	{
		printf("Error in get2DimDoubleArray() -file pointer is NULL !!\n");
		exit(-1);
	}

	for (int m = 0; m < row_size; m++)
		for (int n = 0; n < col_size; n++)
		{
			if (fscanf(fp, "%lf", &d) != EOF) //파일에서 숫자를 읽어옴
				dM[m][n] = d;	//읽어온 숫자를 배열에 저장
		}
}

// 배열을 실행화면에 출력하는 함수
void print2DimDoubleArray(double** mA, int row_size, int col_size)
{
	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			printf("%8.2lf", mA[m][n]);	//배열을 출력
		}
		printf("\n");	//줄바꿈
	}
}

// 배열의 행의 평균을 구하는 함수
double getRow_Avg(double** array, int row, int num_cols)
{
	double sum = 0.0, row_avg;

	for (int i = 0; i < num_cols; i++)
	{
		sum += array[row][i]; //배열의 행의 숫자를 모두 더함
	}

	row_avg = sum / (double)num_cols;	//더한 숫자를 한 행의 크기로 나눔(평균)

	return row_avg;	//평균 반환
}

//2차원 배열 전체 원소의 평균을 구하는 함수
double getTotalAvg(double** array, int num_rows, int num_cols)
{
	double sum = 0.0, avg;

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			sum += array[r][c];	//배열의 전체 원소를 모두 다 더함
		}
	}

	avg = sum / (double)(num_rows * num_cols); //더한 숫자를 배열의 크기로 나눔(평균)

	return avg;	//평균 반환
}
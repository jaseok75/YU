/* Two_Dim_Array_Operations.h */
#ifndef TWO_DIM_ARRAY_OPERATIONS_H	//h 파일이 선언되지 않았다면 선언하기
#define TWO_DIM_ARRAY_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "Two_Dim_Array_Operations.h"

//사용할 함수 선언하기
double** create2DimDoubleArray(int row_size, int col_size);
void delete2DimDoubleArray(double** dM, int row_size, int col_size);
void fget2DimDoubleArray(FILE* fp, double** dM, int row_size, int col_size);
void print2DimDoubleArray(double** mA, int row_size, int col_size);
double getRow_Avg(double** array, int row, int num_cols);
double getTotalAvg(double** array, int num_rows, int num_cols);

//ifndef 종료하기
#endif
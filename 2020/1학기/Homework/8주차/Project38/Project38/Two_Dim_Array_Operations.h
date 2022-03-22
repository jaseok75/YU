/* Two_Dim_Array_Operations.h */
#ifndef TWO_DIM_ARRAY_OPERATIONS_H	//h ������ ������� �ʾҴٸ� �����ϱ�
#define TWO_DIM_ARRAY_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "Two_Dim_Array_Operations.h"

//����� �Լ� �����ϱ�
double** create2DimDoubleArray(int row_size, int col_size);
void delete2DimDoubleArray(double** dM, int row_size, int col_size);
void fget2DimDoubleArray(FILE* fp, double** dM, int row_size, int col_size);
void print2DimDoubleArray(double** mA, int row_size, int col_size);
double getRow_Avg(double** array, int row, int num_cols);
double getTotalAvg(double** array, int num_rows, int num_cols);

//ifndef �����ϱ�
#endif
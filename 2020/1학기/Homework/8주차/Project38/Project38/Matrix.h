/* Matrix.h */
#define _CRT_SECURE_NO_WARNINGS
#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

double** createDynamicDoubleMatrix(int row_size, int col_size);
void deleteDynamicDoubleMatrix(double** dM, int row_size, int col_size);
void fgetMtrx(FILE* fp, double** dM, int row_size, int col_size);
void initMtrx(FILE* fin, double** mA, int* size_row, int* size_column);
void printMtrx(double** mA, int row_size, int col_size);
void fprintMtrx(FILE* fout, double** mA, int row_size, int col_size);
void addMtrx(double** mC, double** mA, double** mB, int row_size, int col_size);
void subtractMtrx(double** mC, double** mA, double** mB, int row_size, int col_size);
void multiplyMtrx(double** mC, double** mA, double** mB, int a_row_size, int a_col_size, int b_col_size);


#endif
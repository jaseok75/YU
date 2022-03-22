/* GaussJordan_LinearSystem.h */

#ifndef GAUSSJORDAN_LINEARSYSTEM_H
#define GAUSSJORDAN_LINEARSYSTEM_H

#include <stdio.h>
#include <math.h>
#include "Matrix.h"
#include "GaussJordan_LinearSystem.h"
#define EPSILON 0.000001

void fgetDoubleAugMtrx(FILE* fin, double** augMtrx, int size_N);
void pivoting(double** augMtrx, int size_N, int p, int* piv_found);
//void diagonalize(double** mtrxAug, int size_N, int* solExist);
void diagonalize(FILE* fout, double** mtrxAug, int size_N, int* solExist);
void inverseMtrx(double** mA, double** inv_A, int size_N);

#endif
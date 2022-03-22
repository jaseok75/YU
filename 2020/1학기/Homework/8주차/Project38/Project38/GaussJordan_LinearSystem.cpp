/* GaussJordan_LinearSystem.cpp */
#include <stdio.h>
#include <math.h>
#include "Matrix.h"
#include "GaussJordan_LinearSystem.h"

// 파일에서 숫자를 읽어 배열에 저장하는 함수
void fgetDoubleAugMtrx(FILE* fin, double** dM, int size_N)
{
	double d = 0.0;

	//파일이 제대로 되지 않았다면 중지
	if (fin == NULL)
	{
		printf("Error in getDoubleMatrixData() - file pointer is NULL!!\n");
		exit(-1);
	}

	for (int m = 0; m < size_N; m++)
		for (int n = 0; n <= size_N; n++)
		{
			if (fscanf(fin, "%lf", &d) != EOF)	//파일에서 숫자 읽어오기
				dM[m][n] = d;	//읽어온 숫자를 배열에 저장하기
		}
}

// 아직 p번째 이후의 행(row)들 중에서 p번째 원소의 절대값이 가장 큰 행을 p번째 행으로 선정하고 필요한 경우 swap하는 함수
void pivoting(double** augMtrx, int size_N, int p, int* piv_found)
{
	double xmax = 0.0, xtemp;
	int j, k, max_row;

	//find maximum pivot
	xmax = fabs(augMtrx[p][p]);	//p번째 행, p번째 원소의 절댓값을 xmax에 저장
	max_row = p;	//가장 큰 행을 p번째 행으로 저장

	for (j = p + 1; j < size_N; j++)
	{
		if (fabs(augMtrx[j][p]) > xmax)	//p번째 이후의 행들 중에서 절댓값이 가장 큰 값을 xmax에 저장
		{
			xmax = fabs(augMtrx[j][p]);
			max_row = j;
		} //end if
	} // end for

	//swap rows if non-zero pivot was found
	if (fabs(xmax) < EPSILON)
	{
		*piv_found = 0;	//False
	}

	else
	{
		*piv_found = 1; //True

		if (max_row != p)
		{
			//swap rows
			for (k = p; k <= size_N; k++)
			{
				// augMtrx[p][k]와 augMtrx[max_row][k] swap하기
				xtemp = augMtrx[p][k];
				augMtrx[p][k] = augMtrx[max_row][k];
				augMtrx[max_row][k] = xtemp;
			} //end for
		} //end if
	} //end if-else
}

//p번째 열의 p번째 원소 값만 1.0이 되게 하고, 나머지 행들의 원소들은 모두 0.0이 되도록 소거 연산 수행하는 함수
void diagonalize(FILE* fout, double** mtrxAug, int size_N, int* solExist)
{
	int j, k, p = 0;
	double pivWeight, w;
	//Pivoting and Scaling

	for (p = 0; (*solExist) && (p < size_N); p++)
	{
		fprintf(fout, "\nPivoting at p = %d\n", p);
		pivoting(mtrxAug, size_N, p, solExist);
		fprintMtrx(fout, mtrxAug, size_N, size_N + 1);	//배열을 파일에 출력하는 함수

		if (*solExist)
		{
			//scaling the elements in pivot row

			if (mtrxAug[p][p] != 1.0)
			{
				//adjust pivot row, if the pivot is not 1.0
				pivWeight = mtrxAug[p][p]; //scaling value pivot row
				mtrxAug[p][p] = 1.0; // make the diagonal element at pivot row into 1.0

				//p번째 행, p번째 원소를 제외한 나머지 원소들을 0.0으로 만들기
				for (k = p + 1; k <= size_N; k++)
				{
					mtrxAug[p][k] /= pivWeight;
				}
			}
		}

		else
		{
			break;
		}

		fprintf(fout, "\nAfter scaling at p = %d\n", p);
		fprintMtrx(fout, mtrxAug, size_N, size_N + 1);

		for (j = 0; j < size_N; j++)
		{
			if ((j != p) && (mtrxAug[j][p] != 0.0))
			{
				w = mtrxAug[j][p];
				mtrxAug[j][p] = 0.0;

				for (k = p + 1; k <= size_N; k++)
				{
					mtrxAug[j][k] = mtrxAug[j][k] - w * mtrxAug[p][k];
				}
			}
		}

		fprintf(fout, "\nAfter diagonalizing at p = %d\n", p);
		fprintMtrx(fout, mtrxAug, size_N, size_N + 1);	//배열을 파일에 출력하기
	}
}

// 역행렬 구하는 함수
void inverseMtrx(double** mA, double** inv_A, int size_N)
{
	int j, k, p = 0; //pivot index
	double pivWeight, w;
	double** mAUG; //augment matrix in N x 2N size for {A | 1}

	//Part 1. Prepare the n x 2n augmented matrix mAUG[N][2N]
	mAUG = (double**)calloc(size_N, sizeof(double*));	//동적할당

	for (int i = 0; i < size_N; i++)
	{
		mAUG[i] = (double*)calloc(size_N * 2, sizeof(double));	//동적 할당
	}

	for (j = 0; j < size_N; j++)
	{
		for (k = 0; k < size_N; k++)
		{
			mAUG[j][k] = mA[j][k];
		}

		for (k = size_N; k < size_N * 2; k++)
		{
			mAUG[j][k] = (k == (j + size_N)) ? 1.0 : 0.0;
		}
	}

	// Part 2. Scaling and Elimination of coefficients of above and below
	//		   the diagonal elements of mAUG[][]

	for (p = 0; p < size_N; p++)
	{
		//scaling
		if (mAUG[p][p] != 1.0)
		{
			//adjust pivot row, if the pivot is not 1.0
			pivWeight = mAUG[p][p];
			mAUG[p][p] = 1.0;

			for (k = p + 1; k < size_N * 2; k++)
			{
				mAUG[p][k] /= pivWeight; //scaling the elements in pivot row
			}
		}

		// eliminate coefficients above and below the pivot row

		for (j = 0; j < size_N; j++)
		{
			// for j-th row
			if ((j != p) && (mAUG[j][p] != 0.0))
			{
				w = mAUG[j][p]; //weight
				mAUG[j][p] = 0.0;	//eliminate coefficients, just except the pivot row

				for (k = p + 1; k < 2 * size_N; k++)
				{
					mAUG[j][k] -= w * mAUG[p][k];	//Rj = Rj - w * Rp
				}
			}
		}
	}

	// Part 3. Copy the result inverse matrix to inv_A[][]
	//계산된 역행렬 저장
	for (j = 0; j < size_N; j++)
	{
		for (k = 0; k < size_N; k++)
		{
			inv_A[j][k] = mAUG[j][k + size_N];
		}
	}
}
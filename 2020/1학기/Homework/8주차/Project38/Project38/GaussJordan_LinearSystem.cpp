/* GaussJordan_LinearSystem.cpp */
#include <stdio.h>
#include <math.h>
#include "Matrix.h"
#include "GaussJordan_LinearSystem.h"

// ���Ͽ��� ���ڸ� �о� �迭�� �����ϴ� �Լ�
void fgetDoubleAugMtrx(FILE* fin, double** dM, int size_N)
{
	double d = 0.0;

	//������ ����� ���� �ʾҴٸ� ����
	if (fin == NULL)
	{
		printf("Error in getDoubleMatrixData() - file pointer is NULL!!\n");
		exit(-1);
	}

	for (int m = 0; m < size_N; m++)
		for (int n = 0; n <= size_N; n++)
		{
			if (fscanf(fin, "%lf", &d) != EOF)	//���Ͽ��� ���� �о����
				dM[m][n] = d;	//�о�� ���ڸ� �迭�� �����ϱ�
		}
}

// ���� p��° ������ ��(row)�� �߿��� p��° ������ ���밪�� ���� ū ���� p��° ������ �����ϰ� �ʿ��� ��� swap�ϴ� �Լ�
void pivoting(double** augMtrx, int size_N, int p, int* piv_found)
{
	double xmax = 0.0, xtemp;
	int j, k, max_row;

	//find maximum pivot
	xmax = fabs(augMtrx[p][p]);	//p��° ��, p��° ������ ������ xmax�� ����
	max_row = p;	//���� ū ���� p��° ������ ����

	for (j = p + 1; j < size_N; j++)
	{
		if (fabs(augMtrx[j][p]) > xmax)	//p��° ������ ��� �߿��� ������ ���� ū ���� xmax�� ����
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
				// augMtrx[p][k]�� augMtrx[max_row][k] swap�ϱ�
				xtemp = augMtrx[p][k];
				augMtrx[p][k] = augMtrx[max_row][k];
				augMtrx[max_row][k] = xtemp;
			} //end for
		} //end if
	} //end if-else
}

//p��° ���� p��° ���� ���� 1.0�� �ǰ� �ϰ�, ������ ����� ���ҵ��� ��� 0.0�� �ǵ��� �Ұ� ���� �����ϴ� �Լ�
void diagonalize(FILE* fout, double** mtrxAug, int size_N, int* solExist)
{
	int j, k, p = 0;
	double pivWeight, w;
	//Pivoting and Scaling

	for (p = 0; (*solExist) && (p < size_N); p++)
	{
		fprintf(fout, "\nPivoting at p = %d\n", p);
		pivoting(mtrxAug, size_N, p, solExist);
		fprintMtrx(fout, mtrxAug, size_N, size_N + 1);	//�迭�� ���Ͽ� ����ϴ� �Լ�

		if (*solExist)
		{
			//scaling the elements in pivot row

			if (mtrxAug[p][p] != 1.0)
			{
				//adjust pivot row, if the pivot is not 1.0
				pivWeight = mtrxAug[p][p]; //scaling value pivot row
				mtrxAug[p][p] = 1.0; // make the diagonal element at pivot row into 1.0

				//p��° ��, p��° ���Ҹ� ������ ������ ���ҵ��� 0.0���� �����
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
		fprintMtrx(fout, mtrxAug, size_N, size_N + 1);	//�迭�� ���Ͽ� ����ϱ�
	}
}

// ����� ���ϴ� �Լ�
void inverseMtrx(double** mA, double** inv_A, int size_N)
{
	int j, k, p = 0; //pivot index
	double pivWeight, w;
	double** mAUG; //augment matrix in N x 2N size for {A | 1}

	//Part 1. Prepare the n x 2n augmented matrix mAUG[N][2N]
	mAUG = (double**)calloc(size_N, sizeof(double*));	//�����Ҵ�

	for (int i = 0; i < size_N; i++)
	{
		mAUG[i] = (double*)calloc(size_N * 2, sizeof(double));	//���� �Ҵ�
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
	//���� ����� ����
	for (j = 0; j < size_N; j++)
	{
		for (k = 0; k < size_N; k++)
		{
			inv_A[j][k] = mAUG[j][k + size_N];
		}
	}
}
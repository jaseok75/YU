/* Matrix.cpp */
#include "Matrix.h"

// �μ��� �޾ƿ� �����ŭ ������ �迭 �����ϴ� �Լ�
double** createDynamicDoubleMatrix(int row_size, int col_size)
{
	double** dM;

	dM = (double**)calloc(row_size, sizeof(double*));//���� �Ҵ�
	for (int r = 0; r < row_size; r++)
	{
		dM[r] = (double*)calloc(col_size, sizeof(double));	//���� �Ҵ�
	}

	return dM;
}

//���� �Ҵ� �����ϴ� �Լ�
void deleteDynamicDoubleMatrix(double** dM, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(dM[r]);	//���� �Ҵ� ����
	}

	free(dM);	//���� �Ҵ� ����
}

//���Ͽ��� ���ڸ� �о�� �迭�� �����ϴ� �Լ�
void fgetMtrx(FILE* fp, double** dM, int row_size, int col_size)
{
	double d = 0.0;

	// ������ ����� ������ �ʾҴٸ� ����
	if (fp == NULL)
	{
		printf("Error in getDoubleMatrixData() -file pointer is NULL !!\n");
		exit(-1);
	}

	for (int m = 0; m < row_size; m++)
		for (int n = 0; n < col_size; n++)
		{
			if (fscanf(fp, "%lf", &d) != EOF)	//���Ͽ��� ���� �о����
				dM[m][n] = d;	//�迭�� ����
		}
}

//������ �迭�� ������ �迭 �����ϱ�
void initMtrx(FILE* fin, double** mA, int* size_row, int* size_column)
{
	fgetMtrx(fin, mA, *size_row, *size_column);	//���Ͽ��� ���ڸ� �о�� �迭�� �����ϴ� �Լ� �ҷ�����
}

//���Ͽ� �迭�� ����ϴ� �Լ�(Ȯ����)
void fprintMtrx(FILE* fout, double** mA, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;

	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			if ((m == 0) && (n == 0))
			{
				if (row_size == 1)
					fprintf(fout, "[ %15.4lf", mA[m][n]);

				else
					fprintf(fout, "%c%c%15.4lf", a6, a3, mA[m][n]);

				if (col_size == 1)
					fprintf(fout, "\t%c%c", a6, a4);
			}

			else if ((m == 0) && n == (col_size - 1))
			{
				if (row_size == 1)
					fprintf(fout, "%15.4lf ]", mA[m][n]);

				else fprintf(fout, "%15.4lf\t%c%c", mA[m][n], a6, a4);
			}

			else if ((m > 0) && (m < row_size - 1) && (n == 0))
			{
				fprintf(fout, "%c%c%15.4lf", a6, a2, mA[m][n]);

				if (col_size == 1)
					fprintf(fout, "\t%c%c", a6, a2);
			}

			else if ((m > 0) && (m < row_size - 1) && (n == (col_size - 1)))
				fprintf(fout, "%15.4lf\t%c%c", mA[m][n], a6, a2);

			else if ((m == (row_size - 1)) && (n == 0))
			{
				fprintf(fout, "%c%c%15.4lf", a6, a6, mA[m][n]);

				if (col_size == 1)
					fprintf(fout, "\t%c%c", a6, a5);
			}

			else if ((m == (row_size - 1)) && (n == (col_size - 1)))
			{
				fprintf(fout, "%15.4lf\t%c%c", mA[m][n], a6, a5);
			}

			else
				fprintf(fout, "%15.4lf", mA[m][n]);
		} // end for (inner loop) 
		fprintf(fout, "\n");
	} // end for (outer loop)
}

//�迭�� ����ȭ�鿡 ����ϴ� �Լ�(Ȯ����)
void printMtrx(double** mA, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;

	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			if ((m == 0) && (n == 0))
			{
				if (row_size == 1)
					printf("[ %10.4lf", mA[m][n]);

				else
					printf("%c%c%10.4lf", a6, a3, mA[m][n]);

				if (col_size == 1)
					printf(" %c%c", a6, a4);
			}

			else if ((m == 0) && n == (col_size - 1))
			{
				if (row_size == 1)
					printf("%10.4lf ]", mA[m][n]);

				else
					printf("%10.4lf %c%c", mA[m][n], a6, a4);
			}

			else if ((m > 0) && (m < row_size - 1) && (n == 0))
			{
				printf("%c%c%10.4lf", a6, a2, mA[m][n]);

				if (col_size == 1)
					printf(" %c%c", a6, a2);
			}

			else if ((m > 0) && (m < row_size - 1) && (n == (col_size - 1)))
				printf("%10.4lf %c%c", mA[m][n], a6, a2);

			else if ((m == (row_size - 1)) && (n == 0))
			{
				printf("%c%c%10.4lf", a6, a6, mA[m][n]);

				if (col_size == 1)
					printf(" %c%c", a6, a5);
			}

			else if ((m == (row_size - 1)) && (n == (col_size - 1)))
			{
				printf("%10.4lf %c%c", mA[m][n], a6, a5);
			}

			else
				printf("%10.4lf", mA[m][n]);
		} // end for (inner loop)
		printf("\n");
	} // end for (outer loop)
}

//����� ������ ����ؼ� �迭�� �����ϴ� �Լ�
void addMtrx(double** mC, double** mA, double** mB, int row_size, int col_size)
{
	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			mC[m][n] = mA[m][n] + mB[m][n];		//����� ���� ��� �� ����
		}
	}
}

//����� ������ ����ؼ� �迭�� �����ϴ� �Լ�
void subtractMtrx(double** mC, double** mA, double** mB, int row_size, int col_size)
{
	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			mC[m][n] = mA[m][n] - mB[m][n];		//����� ���� ��� �� ����
		}
	}
}

//����� ���� ��� �� �迭�� ����
void multiplyMtrx(double** mC, double** mA, double** mB, int a_row_size, int a_col_size, int b_col_size)
{
	for (int m = 0; m < a_row_size; m++)
	{
		for (int n = 0; n < b_col_size; n++)
		{
			mC[m][n] = 0;

			for (int k = 0; k < a_col_size; k++)
			{
				mC[m][n] += mA[m][k] * mB[k][n];	//����� ���� ��� �� ����
			}
		}
	}
}
/* Matrix.cpp */
#include "Matrix.h"

// 인수로 받아온 사이즈만큼 포인터 배열 생성하는 함수
double** createDynamicDoubleMatrix(int row_size, int col_size)
{
	double** dM;

	dM = (double**)calloc(row_size, sizeof(double*));//동적 할당
	for (int r = 0; r < row_size; r++)
	{
		dM[r] = (double*)calloc(col_size, sizeof(double));	//동적 할당
	}

	return dM;
}

//동적 할당 해제하는 함수
void deleteDynamicDoubleMatrix(double** dM, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(dM[r]);	//동적 할당 해제
	}

	free(dM);	//동적 할당 해제
}

//파일에서 숫자를 읽어와 배열에 저장하는 함수
void fgetMtrx(FILE* fp, double** dM, int row_size, int col_size)
{
	double d = 0.0;

	// 파일이 제대로 열리지 않았다면 중지
	if (fp == NULL)
	{
		printf("Error in getDoubleMatrixData() -file pointer is NULL !!\n");
		exit(-1);
	}

	for (int m = 0; m < row_size; m++)
		for (int n = 0; n < col_size; n++)
		{
			if (fscanf(fp, "%lf", &d) != EOF)	//파일에서 숫자 읽어오기
				dM[m][n] = d;	//배열에 저장
		}
}

//포인터 배열에 파일의 배열 저장하기
void initMtrx(FILE* fin, double** mA, int* size_row, int* size_column)
{
	fgetMtrx(fin, mA, *size_row, *size_column);	//파일에서 숫자를 읽어와 배열에 저장하는 함수 불러오기
}

//파일에 배열을 출력하는 함수(확장형)
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

//배열을 실행화면에 출력하는 함수(확장형)
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

//행렬의 덧셈을 계산해서 배열에 저장하는 함수
void addMtrx(double** mC, double** mA, double** mB, int row_size, int col_size)
{
	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			mC[m][n] = mA[m][n] + mB[m][n];		//행렬의 덧셈 계산 후 저장
		}
	}
}

//행렬의 뺄셈을 계산해서 배열에 저장하는 함수
void subtractMtrx(double** mC, double** mA, double** mB, int row_size, int col_size)
{
	for (int m = 0; m < row_size; m++)
	{
		for (int n = 0; n < col_size; n++)
		{
			mC[m][n] = mA[m][n] - mB[m][n];		//행렬의 덧셈 계산 후 저장
		}
	}
}

//행렬의 곱셈 계산 후 배열에 저장
void multiplyMtrx(double** mC, double** mA, double** mB, int a_row_size, int a_col_size, int b_col_size)
{
	for (int m = 0; m < a_row_size; m++)
	{
		for (int n = 0; n < b_col_size; n++)
		{
			mC[m][n] = 0;

			for (int k = 0; k < a_col_size; k++)
			{
				mC[m][n] += mA[m][k] * mB[k][n];	//행렬의 곱셈 계산 후 저장
			}
		}
	}
}
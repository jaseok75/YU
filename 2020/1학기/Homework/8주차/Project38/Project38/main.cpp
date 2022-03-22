/*
 * ���ϸ�: "Homeword08_21912150_���ϸ�_Lab08_main.cpp"
 * ���α׷��� ���� �� �⺻ ���:
 * - �� ���α׷��� �޴��� �Է¹޾� �� �޴��� �ش��ϴ� �پ��� ����� ������ �ϴ� ���α׷��̴�.
 *
 * ���α׷� �ۼ���: ���ϸ�(2020�� 05�� 21��)
 * ���� Update : 2020�� 05�� 21��(���ϸ�).
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Matrix.h"
#include "GaussJordan_LinearSystem.h"

const char* outputFile = "OutputResult.txt";
void test_2D_DynamicArray_FileIO(FILE* fout);
void test_MatrixAdditionSubtraction(FILE* fout);
void test_MatrixMultiplication(FILE* fout);
void test_GaussJordanElimination_LinearSystem(FILE* fout);
void test_InvMtrx_GaussJordanElimination_LinearSystem(FILE* fout);

int main(void)
{
	FILE* fin, * fout;
	int menu;

	fout = fopen(outputFile, "w");

	if (fout == NULL)
	{
		printf("Error in opening input.txt file!!\n");
		exit(-1);
	}

	while (1)
	{
		printf("Testing Matrix Operations with 2-Dimensional Dynamic Array\n");
		printf(" 1: Test 2-D Dynamic Array Creation for Matrix with File I/O\n");
		printf(" 2: Test Matrix Addition, Subtraction\n");
		printf(" 3: Test Matrix Multiplicaion\n");
		printf(" 4: Test Gauss-Jordan Elimination for Linear System\n");
		printf(" 5: Test Inverse Matrix with Gauss-Jordan Elimination for Linear System\n");
		printf("-1: Quit\n");
		printf("Input menu (-1 to quit): ");
		scanf("%d", &menu);

		if (menu == -1)
		{
			break;
		}
		printf("\n");

		switch (menu)
		{
		case 1:	//1���� ������ ��
			test_2D_DynamicArray_FileIO(fout);
			break;
		case 2:	//2���� ������ ��
			test_MatrixAdditionSubtraction(fout);
			break;
		case 3:	//3���� ������ ��
			test_MatrixMultiplication(fout);
			break;
		case 4:	//4���� ������ ��
			test_GaussJordanElimination_LinearSystem(fout);
			break;
		case 5:	//5���� ������ ��
			test_InvMtrx_GaussJordanElimination_LinearSystem(fout);
			break;
		default:	//������ ��ȣ �̿��� ���� ������ ��
			break;
		}
	}
	fclose(fout);
}

//1���� ������ ��
void test_2D_DynamicArray_FileIO(FILE* fout)
{
	const char* matrixDataFile = "mtrxInputData.txt";
	FILE* fin;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int* a_row, * a_col = 0;
	int* b_row, * b_col = 0;
	double** dMA, ** dMB;

	a_row = &a_row_size;
	a_col = &a_col_size;
	b_row = &b_row_size;
	b_col = &b_col_size;

	fin = fopen(matrixDataFile, "r");	//������ �б���� ����

	//������ ����� ������ �ʾҴٸ� ���� �����ϱ�
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}

	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//���Ͽ��� �迭�� ������ �о����
	
	*a_row = a_row_size;
	*a_col = a_col_size;

	dMA = createDynamicDoubleMatrix(a_row_size, a_col_size);	//�迭�� �����ŭ ������ �迭 �����ϱ�
	initMtrx(fin, dMA, a_row, a_col);	//���� ���� �迭 �о ������ �迭�� �����ϱ�
	printf("Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);	//�迭�� ���� ȭ�鿡 ����ϱ�
	fprintf(fout, "Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	fprintMtrx(fout, dMA, a_row_size, a_col_size);	//�迭�� ��� ���Ͽ� ����ϱ�
	printf("\n");
	fprintf(fout, "\n");

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);	//���Ͽ��� �迭�� ������ �о����

	*b_row = b_row_size;
	*b_col = b_col_size;

	dMB = createDynamicDoubleMatrix(b_row_size, b_col_size);	//�迭�� �����ŭ ������ �迭 �����ϱ�
	initMtrx(fin, dMB, b_row, b_col);	//���� ���� �迭 �о ������ �迭�� �����ϱ�
	printf("Input Matrix_B ( %d x %d ):\n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);	//�迭�� ���� ȭ�鿡 ����ϱ�
	fprintf(fout, "Input Matrix_B ( %d x %d ):\n", b_row_size, b_col_size);
	fprintMtrx(fout, dMB, b_row_size, b_col_size);	//�迭�� ��� ���Ͽ� ����ϱ�
	printf("\n");
	fprintf(fout, "\n");

	fclose(fin);	//���� �ݱ�
}

//2���� ������ ��
void test_MatrixAdditionSubtraction(FILE* fout)
{
	const char* matrixDataFile = "mtrx_nxn_InputData.txt";
	FILE* fin;

	double** dMA, ** dMB, ** dMC, ** dMD;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	int d_row_size, d_col_size;
	int* a_row, * a_col;
	int* b_row, * b_col;

	a_row = &a_row_size;
	a_col = &a_col_size;
	b_row = &b_row_size;
	b_col = &b_col_size;

	// ������ �б���� ����
	fin = fopen(matrixDataFile, "r");

	// ������ ����� ������ �ʾҴٸ� ����
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}

	// ���Ͽ��� �迭�� ������ �о����
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);

	*a_row = a_row_size;
	*a_col = a_col_size;

	dMA = createDynamicDoubleMatrix(a_row_size, a_col_size);	//�迭�� �����ŭ ������ �迭 �����ϱ�
	initMtrx(fin, dMA, a_row, a_col);
	printf("Input Matrix_A ( %d x %d ) : \n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);	//�迭�� ����ȭ�鿡 ����ϴ� �Լ�
	fprintf(fout, "Input Matrix_A ( %d x %d ) : \n", a_row_size, a_col_size);
	fprintMtrx(fout, dMA, a_row_size, a_col_size);	//�迭�� ���Ͽ� ����ϴ� �Լ�
	printf("\n");
	fprintf(fout, "\n");

	//���Ͽ��� �迭�� ������ �о����
	fscanf(fin, "%d %d", &b_row_size, &b_col_size);

	*b_row = b_row_size;
	*b_col = b_col_size;

	dMB = createDynamicDoubleMatrix(b_row_size, b_col_size);	//�迭�� �����ŭ ������ �迭 �����ϱ�
	initMtrx(fin, dMB, b_row, b_col);
	printf("Input Matrix_B ( %d x %d ) :\n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);	//�迭�� ����ȭ�鿡 ����ϴ� �Լ�
	fprintf(fout, "Input Matrix_B ( %d x %d ) :\n", b_row_size, b_col_size);
	fprintMtrx(fout, dMB, b_row_size, b_col_size);	//�迭�� ���Ͽ� ����ϴ� �Լ�
	printf("\n");
	fprintf(fout, "\n");

	//����� ������ ����ϱ� ��, ����� ���� ������ ���� �ʴ� ��� ����
	if ((a_row_size != b_row_size) || (a_col_size != b_col_size))
	{
		printf("Error in input matrix dimension: row_size and/or col_size are not equal!!\n");
		fclose(fin);	//���� �ݱ�
		return;
	}

	// MC = MA + MB
	c_row_size = a_row_size;
	c_col_size = b_col_size;

	dMC = createDynamicDoubleMatrix(c_row_size, c_col_size);	//������ ����� �迭�� ������ ������ �迭 �����ϱ�
	addMtrx(dMC, dMA, dMB, a_row_size, a_col_size);	// ����� ������ ����� �� ������ �迭�� �����ϱ�
	printf("Matrix_C ( %d + %d ) = Matrix_A x Matrix_B :\n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);	//����ȭ�鿡 �迭�� ����ϴ� �Լ�
	fprintf(fout, "Matrix_C ( %d + %d ) = Matrix_A x Matrix_B :\n", c_row_size, c_col_size);
	fprintMtrx(fout, dMC, c_row_size, c_col_size);	//���Ͽ� �迭�� ����ϴ� �Լ�
	printf("\n");
	fprintf(fout, "\n");

	d_row_size = a_row_size;
	d_col_size = b_col_size;

	dMD = createDynamicDoubleMatrix(d_row_size, c_col_size);	//������ ����� �迭�� ������ ������ �迭 �����ϱ�
	subtractMtrx(dMD, dMA, dMB, a_row_size, d_col_size);	// ����� ������ ����� �� ������ �迭�� �����ϱ�
	printf("Matrix_D ( %d - %d ) = Matrix_A x Matrix_B:\n", d_row_size, c_col_size);
	printMtrx(dMD, d_row_size, d_col_size);	//����ȭ�鿡 �迭�� ����ϴ� �Լ�
	fprintf(fout, "Matrix_D ( %d - %d ) = Matrix_A x Matrix_B:\n", d_row_size, c_col_size);
	fprintMtrx(fout, dMD, d_row_size, d_col_size);	//���Ͽ� �迭�� ����ϴ� �Լ�
	printf("\n");
	fprintf(fout, "\n");

	//�����Ҵ� ����
	deleteDynamicDoubleMatrix(dMA, a_row_size, a_col_size);
	deleteDynamicDoubleMatrix(dMB, b_row_size, b_col_size);
	deleteDynamicDoubleMatrix(dMC, c_row_size, c_col_size);
	deleteDynamicDoubleMatrix(dMD, d_row_size, d_col_size);

	fclose(fin);	//���� �ݱ�
}

//3���� ������ ���� �Լ�
void test_MatrixMultiplication(FILE* fout)
{
	const char* matrixDataFile = "mtrxInputData.txt";
	FILE* fin;

	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	int* a_row, * a_col;
	int* b_row, * b_col;
	double** dMA, ** dMB, ** dMC;

	a_row = &a_row_size;
	a_col = &a_col_size;
	b_row = &b_row_size;
	b_col = &b_col_size;

	// ������ �б���� ����
	fin = fopen(matrixDataFile, "r");

	// ������ ����� ������ �ʾҴٸ� ����
	if (fin == NULL)
	{
		printf("Error in opening input.txt file!!\n");
		exit(-1);
	}

	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//�迭�� ������ �о����
	
	*a_row = a_row_size;
	*a_col = a_col_size;

	dMA = createDynamicDoubleMatrix(a_row_size, a_col_size);	//�迭�� �����ŭ ������ �迭 �����ϱ�
	initMtrx(fin, dMA, a_row, a_col);
	printf("Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);	// �迭�� ����ȭ�鿡 ����ϱ�
	fprintf(fout, "Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	fprintMtrx(fout, dMA, a_row_size, a_col_size);	//���Ͽ� �迭�� ����ϱ�
	printf("\n");
	fprintf(fout, "\n");

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);	// �迭�� ������ �о����
	
	*b_row = b_row_size;
	*b_col = b_col_size;

	dMB = createDynamicDoubleMatrix(b_row_size, b_col_size);	//�迭�� �����ŭ ������ �迭 �����ϱ�
	initMtrx(fin, dMB, b_row, b_col);
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);	//�迭�� ����ȭ�鿡 ����ϱ�
	fprintf(fout, "Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);
	fprintMtrx(fout, dMB, b_row_size, b_col_size);	//�迭�� ���Ͽ� ����ϱ�
	printf("\n");
	fprintf(fout, "\n");

	// MC = MA x MB  
	c_row_size = a_row_size;
	c_col_size = b_col_size;

	dMC = createDynamicDoubleMatrix(c_row_size, c_col_size);	//������ ����� ������ �迭�� �����ϱ�
	multiplyMtrx(dMC, dMA, dMB, a_row_size, a_col_size, b_col_size);	//����� ���� ��� �� �迭�� �����ϱ�
	printf("Matrix_C (%d x %d) = Matrix_A x Matrix_B : \n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);	//�迭�� ����ȭ�鿡 ����ϱ�
	fprintf(fout, "Matrix_C (%d x %d) = Matrix_A x Matrix_B : \n", c_row_size, c_col_size);
	fprintMtrx(fin, dMC, c_row_size, c_col_size);	//�迭�� ���Ͽ� ����ϱ�
	printf("\n");
	fprintf(fout, "\n");

	//���� �Ҵ� ����
	deleteDynamicDoubleMatrix(dMA, a_row_size, a_col_size);
	deleteDynamicDoubleMatrix(dMB, b_row_size, b_col_size);
	deleteDynamicDoubleMatrix(dMC, c_row_size, c_col_size);

	fclose(fin);	//���� �ݱ�
}

//4���� ������ ���� �Լ�
//const char *augMatrix_inputFile = "AugMtrx_ElectronicCircuit_A_5x5.txt"; 
const char* augMatrix_inputFile = "AugMtrx_ElectronicCircuit_B_5x5.txt";
void test_GaussJordanElimination_LinearSystem(FILE* fout)
{
	FILE* fin;
	int size_N, row_size, col_size;
	double* solution;
	double** augMtrx = NULL;
	int i, j, solExist = 1, error = 0;
	double d;

	//������ �б���� ����
	fin = fopen(augMatrix_inputFile, "r");

	//������ ����� ������ �ʾҴٸ� ����
	if (fin == NULL)
	{
		printf("Error in opening input.txt file (%s)!!\n", augMatrix_inputFile);
		exit(-1);
	}

	fscanf(fin, "%d", &size_N);	//���Ͽ��� �迭�� ũ�� �о����
	augMtrx = createDynamicDoubleMatrix(size_N, size_N + 1); //������ �迭 �����ϱ�
	solution = (double*)calloc(size_N, sizeof(double));	// ���� �Ҵ�
	fprintf(fout, "Augmented Matrix size_N : %d\n", size_N);
	fgetDoubleAugMtrx(fin, augMtrx, size_N);	//���Ͽ��� �迭 �о ������ �迭�� �����ϱ�
	fprintf(fout, "Augmented Matrix : \n");
	fprintMtrx(fout, augMtrx, size_N, size_N + 1);	//�迭�� ���Ͽ� ����ϱ�
	printf("Augmented Matrix : \n");
	printMtrx(augMtrx, size_N, size_N + 1);	//�迭�� ����ȭ�鿡 ����ϱ�

	diagonalize(fout, (double**)augMtrx, size_N, &solExist);

	if (solExist)
	{
		fprintf(fout, "The solution of the given linear system:\n");
		printf("The solution of the given linear system:\n");
		for (i = 0; i < size_N; i++)
		{
			solution[i] = augMtrx[i][size_N];
			fprintf(fout, " x[%d] : %4f\n", i, solution[i]);
			printf(" x[%d] : %4f\n", i, solution[i]);
		}
	}
	else
	{
		fprintf(fout, "No unique solution\n");
		printf("No unique solution\n");
	}

	for (int i = 0; i < size_N; i++)
		free(augMtrx[i]);	//�����Ҵ�����

	free(augMtrx);	//���� �Ҵ� ����
	free(solution);	//���� �Ҵ� ����
	fclose(fin);	//���� �ݱ�
}

//5���� ������ ���� �Լ�
//const char *linearSystem_inputFile = "ElectronicCircuit_A_5x5.txt"; 
const char* linearSystem_inputFile = "ElectronicCircuit_B_5x5.txt";
void test_InvMtrx_GaussJordanElimination_LinearSystem(FILE* fout)
{
	FILE* fin;
	double** mA, ** inv_A, ** res, ** mI;
	int size_N;  double data;

	// ������ �б���� ����
	//fin = fopen("InputData.txt", "r");  
	fin = fopen(linearSystem_inputFile, "r");
	//fin = fopen("ElectronicCircuit_B_5x5.txt", "r");  

	//������ ����� ������ �ʾҴٸ� ����
	if (fin == NULL)
	{
		printf("Error in openning %s input file !!\n", linearSystem_inputFile);
		exit(-1);
	}

	//���Ͽ��� �迭�� ������ �о����
	fscanf(fin, "%d", &size_N);

	//���� �Ҵ�
	mA = (double**)calloc(size_N, sizeof(double*));
	inv_A = (double**)calloc(size_N, sizeof(double*));
	mI = (double**)calloc(size_N, sizeof(double*));

	//���� �Ҵ�
	for (int i = 0; i < size_N; i++)
	{
		mA[i] = (double*)calloc(size_N, sizeof(double));
		mI[i] = (double*)calloc(size_N, sizeof(double));
		inv_A[i] = (double*)calloc(size_N, sizeof(double));
	}

	//������ �迭���� ���ڸ� �о�� ������ �迭�� �����ϱ�
	for (int r = 0; r < size_N; r++)
		for (int c = 0; c < size_N; c++)
		{
			fscanf(fin, "%lf", &data);
			mA[r][c] = data;
		}

	fprintf(fout, "\n Matrix A: \n");
	fprintMtrx(fout, mA, size_N, size_N);	//�迭�� ���Ͽ� ����ϱ�
	printf("\n Matrix A: \n");
	printMtrx(mA, size_N, size_N);	//�迭�� ����ȭ�鿡 ����ϱ�

	inverseMtrx(mA, inv_A, size_N);	//����� ���ؼ� ������ �迭�� �����ϱ�
	fprintf(fout, " Inverse A: \n");
	fprintMtrx(fout, inv_A, size_N, size_N);	//�迭�� ���Ͽ� ����ϱ�
	printf(" Inverse A: \n");
	printMtrx(inv_A, size_N, size_N);	//�迭�� ����ȭ�鿡 ����ϱ�

	multiplyMtrx(mI, inv_A, mA, size_N, size_N, size_N);	//����� ���� ����ؼ� ������ �迭�� �����ϱ�

	fprintf(fout, " mI: \n");
	fprintMtrx(fout, mI, size_N, size_N);	//�迭�� ���Ͽ� ����ϱ�
	printf(" mI: \n");
	printMtrx(mI, size_N, size_N);	//�迭�� ����ȭ�鿡 ����ϱ�
	fprintf(fout, "\n");
	printf("\n");

	//���� �Ҵ� ����
	for (int i = 0; i < size_N; i++)
	{
		free(mA[i]);
		free(mI[i]);
		free(inv_A[i]);
	}

	//���� �Ҵ� ����
	free(mA);
	free(mI);
	free(inv_A);

	fclose(fin);	//���� �ݱ�
}
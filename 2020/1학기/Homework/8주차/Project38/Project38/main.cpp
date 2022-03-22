/*
 * 파일명: "Homeword08_21912150_김하림_Lab08_main.cpp"
 * 프로그램의 목적 및 기본 기능:
 * - 이 프로그램은 메뉴를 입력받아 각 메뉴에 해당하는 다양한 행렬의 연산을 하는 프로그램이다.
 *
 * 프로그램 작성자: 김하림(2020년 05월 21일)
 * 최종 Update : 2020년 05월 21일(김하림).
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
		case 1:	//1번을 눌렀을 때
			test_2D_DynamicArray_FileIO(fout);
			break;
		case 2:	//2번을 눌렀을 때
			test_MatrixAdditionSubtraction(fout);
			break;
		case 3:	//3번을 눌렀을 때
			test_MatrixMultiplication(fout);
			break;
		case 4:	//4번을 눌렀을 때
			test_GaussJordanElimination_LinearSystem(fout);
			break;
		case 5:	//5번을 눌렀을 때
			test_InvMtrx_GaussJordanElimination_LinearSystem(fout);
			break;
		default:	//지정된 번호 이외의 것을 눌렀을 때
			break;
		}
	}
	fclose(fout);
}

//1번을 눌렀을 때
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

	fin = fopen(matrixDataFile, "r");	//파일을 읽기모드로 열기

	//파일이 제대로 열리지 않았다면 실행 중지하기
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}

	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//파일에서 배열의 사이즈 읽어오기
	
	*a_row = a_row_size;
	*a_col = a_col_size;

	dMA = createDynamicDoubleMatrix(a_row_size, a_col_size);	//배열의 사이즈만큼 포인터 배열 생성하기
	initMtrx(fin, dMA, a_row, a_col);	//파일 안의 배열 읽어서 생성된 배열에 저장하기
	printf("Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);	//배열을 실행 화면에 출력하기
	fprintf(fout, "Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	fprintMtrx(fout, dMA, a_row_size, a_col_size);	//배열을 출력 파일에 출력하기
	printf("\n");
	fprintf(fout, "\n");

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);	//파일에서 배열의 사이즈 읽어오기

	*b_row = b_row_size;
	*b_col = b_col_size;

	dMB = createDynamicDoubleMatrix(b_row_size, b_col_size);	//배열의 사이즈만큼 포인터 배열 생성하기
	initMtrx(fin, dMB, b_row, b_col);	//파일 안의 배열 읽어서 생성된 배열에 저장하기
	printf("Input Matrix_B ( %d x %d ):\n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);	//배열을 실행 화면에 출력하기
	fprintf(fout, "Input Matrix_B ( %d x %d ):\n", b_row_size, b_col_size);
	fprintMtrx(fout, dMB, b_row_size, b_col_size);	//배열을 출력 파일에 출력하기
	printf("\n");
	fprintf(fout, "\n");

	fclose(fin);	//파일 닫기
}

//2번을 눌렀을 때
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

	// 파일을 읽기모드로 열기
	fin = fopen(matrixDataFile, "r");

	// 파일이 제대로 열리지 않았다면 중지
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}

	// 파일에서 배열의 사이즈 읽어오기
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);

	*a_row = a_row_size;
	*a_col = a_col_size;

	dMA = createDynamicDoubleMatrix(a_row_size, a_col_size);	//배열의 사이즈만큼 포인터 배열 생성하기
	initMtrx(fin, dMA, a_row, a_col);
	printf("Input Matrix_A ( %d x %d ) : \n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);	//배열을 실행화면에 출력하는 함수
	fprintf(fout, "Input Matrix_A ( %d x %d ) : \n", a_row_size, a_col_size);
	fprintMtrx(fout, dMA, a_row_size, a_col_size);	//배열을 파일에 출력하는 함수
	printf("\n");
	fprintf(fout, "\n");

	//파일에서 배열의 사이즈 읽어오기
	fscanf(fin, "%d %d", &b_row_size, &b_col_size);

	*b_row = b_row_size;
	*b_col = b_col_size;

	dMB = createDynamicDoubleMatrix(b_row_size, b_col_size);	//배열의 사이즈만큼 포인터 배열 생성하기
	initMtrx(fin, dMB, b_row, b_col);
	printf("Input Matrix_B ( %d x %d ) :\n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);	//배열을 실행화면에 출력하는 함수
	fprintf(fout, "Input Matrix_B ( %d x %d ) :\n", b_row_size, b_col_size);
	fprintMtrx(fout, dMB, b_row_size, b_col_size);	//배열을 파일에 출력하는 함수
	printf("\n");
	fprintf(fout, "\n");

	//행렬의 곱셈을 계산하기 전, 계산을 위한 조건이 맞지 않는 경우 중지
	if ((a_row_size != b_row_size) || (a_col_size != b_col_size))
	{
		printf("Error in input matrix dimension: row_size and/or col_size are not equal!!\n");
		fclose(fin);	//파일 닫기
		return;
	}

	// MC = MA + MB
	c_row_size = a_row_size;
	c_col_size = b_col_size;

	dMC = createDynamicDoubleMatrix(c_row_size, c_col_size);	//덧셈을 계산한 배열을 저장할 포인터 배열 생성하기
	addMtrx(dMC, dMA, dMB, a_row_size, a_col_size);	// 행렬의 덧셈을 계산한 후 포인터 배열에 저장하기
	printf("Matrix_C ( %d + %d ) = Matrix_A x Matrix_B :\n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);	//실행화면에 배열을 출력하는 함수
	fprintf(fout, "Matrix_C ( %d + %d ) = Matrix_A x Matrix_B :\n", c_row_size, c_col_size);
	fprintMtrx(fout, dMC, c_row_size, c_col_size);	//파일에 배열을 출력하는 함수
	printf("\n");
	fprintf(fout, "\n");

	d_row_size = a_row_size;
	d_col_size = b_col_size;

	dMD = createDynamicDoubleMatrix(d_row_size, c_col_size);	//뺄셈을 계산한 배열을 저장할 포인터 배열 생성하기
	subtractMtrx(dMD, dMA, dMB, a_row_size, d_col_size);	// 행렬의 뺄셈을 계산한 후 포인터 배열에 저장하기
	printf("Matrix_D ( %d - %d ) = Matrix_A x Matrix_B:\n", d_row_size, c_col_size);
	printMtrx(dMD, d_row_size, d_col_size);	//실행화면에 배열을 출력하는 함수
	fprintf(fout, "Matrix_D ( %d - %d ) = Matrix_A x Matrix_B:\n", d_row_size, c_col_size);
	fprintMtrx(fout, dMD, d_row_size, d_col_size);	//파일에 배열을 출력하는 함수
	printf("\n");
	fprintf(fout, "\n");

	//동적할당 해제
	deleteDynamicDoubleMatrix(dMA, a_row_size, a_col_size);
	deleteDynamicDoubleMatrix(dMB, b_row_size, b_col_size);
	deleteDynamicDoubleMatrix(dMC, c_row_size, c_col_size);
	deleteDynamicDoubleMatrix(dMD, d_row_size, d_col_size);

	fclose(fin);	//파일 닫기
}

//3번을 눌렀을 때의 함수
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

	// 파일을 읽기모드로 열기
	fin = fopen(matrixDataFile, "r");

	// 파일이 제대로 열리지 않았다면 중지
	if (fin == NULL)
	{
		printf("Error in opening input.txt file!!\n");
		exit(-1);
	}

	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//배열의 사이즈 읽어오기
	
	*a_row = a_row_size;
	*a_col = a_col_size;

	dMA = createDynamicDoubleMatrix(a_row_size, a_col_size);	//배열의 사이즈만큼 포인터 배열 생성하기
	initMtrx(fin, dMA, a_row, a_col);
	printf("Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);	// 배열을 실행화면에 출력하기
	fprintf(fout, "Input Matrix_A ( %d x %d ):\n", a_row_size, a_col_size);
	fprintMtrx(fout, dMA, a_row_size, a_col_size);	//파일에 배열을 출력하기
	printf("\n");
	fprintf(fout, "\n");

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);	// 배열의 사이즈 읽어오기
	
	*b_row = b_row_size;
	*b_col = b_col_size;

	dMB = createDynamicDoubleMatrix(b_row_size, b_col_size);	//배열의 사이즈만큼 포인터 배열 생성하기
	initMtrx(fin, dMB, b_row, b_col);
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);	//배열을 실행화면에 출력하기
	fprintf(fout, "Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);
	fprintMtrx(fout, dMB, b_row_size, b_col_size);	//배열을 파일에 출력하기
	printf("\n");
	fprintf(fout, "\n");

	// MC = MA x MB  
	c_row_size = a_row_size;
	c_col_size = b_col_size;

	dMC = createDynamicDoubleMatrix(c_row_size, c_col_size);	//곱셈한 결과를 저장할 배열을 생성하기
	multiplyMtrx(dMC, dMA, dMB, a_row_size, a_col_size, b_col_size);	//행렬의 곱셈 계산 후 배열에 저장하기
	printf("Matrix_C (%d x %d) = Matrix_A x Matrix_B : \n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);	//배열을 실행화면에 출력하기
	fprintf(fout, "Matrix_C (%d x %d) = Matrix_A x Matrix_B : \n", c_row_size, c_col_size);
	fprintMtrx(fin, dMC, c_row_size, c_col_size);	//배열을 파일에 출력하기
	printf("\n");
	fprintf(fout, "\n");

	//동적 할당 해제
	deleteDynamicDoubleMatrix(dMA, a_row_size, a_col_size);
	deleteDynamicDoubleMatrix(dMB, b_row_size, b_col_size);
	deleteDynamicDoubleMatrix(dMC, c_row_size, c_col_size);

	fclose(fin);	//파일 닫기
}

//4번을 눌렀을 때의 함수
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

	//파일을 읽기모드로 열기
	fin = fopen(augMatrix_inputFile, "r");

	//파일이 제대로 열리지 않았다면 중지
	if (fin == NULL)
	{
		printf("Error in opening input.txt file (%s)!!\n", augMatrix_inputFile);
		exit(-1);
	}

	fscanf(fin, "%d", &size_N);	//파일에서 배열의 크기 읽어오기
	augMtrx = createDynamicDoubleMatrix(size_N, size_N + 1); //포인터 배열 생성하기
	solution = (double*)calloc(size_N, sizeof(double));	// 동적 할당
	fprintf(fout, "Augmented Matrix size_N : %d\n", size_N);
	fgetDoubleAugMtrx(fin, augMtrx, size_N);	//파일에서 배열 읽어서 포인터 배열에 저장하기
	fprintf(fout, "Augmented Matrix : \n");
	fprintMtrx(fout, augMtrx, size_N, size_N + 1);	//배열을 파일에 출력하기
	printf("Augmented Matrix : \n");
	printMtrx(augMtrx, size_N, size_N + 1);	//배열을 실행화면에 출력하기

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
		free(augMtrx[i]);	//동적할당해제

	free(augMtrx);	//동적 할당 해제
	free(solution);	//동적 할당 해제
	fclose(fin);	//파일 닫기
}

//5번을 눌렀을 때의 함수
//const char *linearSystem_inputFile = "ElectronicCircuit_A_5x5.txt"; 
const char* linearSystem_inputFile = "ElectronicCircuit_B_5x5.txt";
void test_InvMtrx_GaussJordanElimination_LinearSystem(FILE* fout)
{
	FILE* fin;
	double** mA, ** inv_A, ** res, ** mI;
	int size_N;  double data;

	// 파일을 읽기모드로 열기
	//fin = fopen("InputData.txt", "r");  
	fin = fopen(linearSystem_inputFile, "r");
	//fin = fopen("ElectronicCircuit_B_5x5.txt", "r");  

	//파일이 제대로 열리지 않았다면 중지
	if (fin == NULL)
	{
		printf("Error in openning %s input file !!\n", linearSystem_inputFile);
		exit(-1);
	}

	//파일에서 배열의 사이즈 읽어오기
	fscanf(fin, "%d", &size_N);

	//동적 할당
	mA = (double**)calloc(size_N, sizeof(double*));
	inv_A = (double**)calloc(size_N, sizeof(double*));
	mI = (double**)calloc(size_N, sizeof(double*));

	//동적 할당
	for (int i = 0; i < size_N; i++)
	{
		mA[i] = (double*)calloc(size_N, sizeof(double));
		mI[i] = (double*)calloc(size_N, sizeof(double));
		inv_A[i] = (double*)calloc(size_N, sizeof(double));
	}

	//파일의 배열에서 숫자를 읽어와 포인터 배열에 저장하기
	for (int r = 0; r < size_N; r++)
		for (int c = 0; c < size_N; c++)
		{
			fscanf(fin, "%lf", &data);
			mA[r][c] = data;
		}

	fprintf(fout, "\n Matrix A: \n");
	fprintMtrx(fout, mA, size_N, size_N);	//배열을 파일에 출력하기
	printf("\n Matrix A: \n");
	printMtrx(mA, size_N, size_N);	//배열을 실행화면에 출력하기

	inverseMtrx(mA, inv_A, size_N);	//역행렬 구해서 포인터 배열에 저장하기
	fprintf(fout, " Inverse A: \n");
	fprintMtrx(fout, inv_A, size_N, size_N);	//배열을 파일에 출력하기
	printf(" Inverse A: \n");
	printMtrx(inv_A, size_N, size_N);	//배열을 실행화면에 출력하기

	multiplyMtrx(mI, inv_A, mA, size_N, size_N, size_N);	//행렬의 곱셈 계산해서 포인터 배열에 저장하기

	fprintf(fout, " mI: \n");
	fprintMtrx(fout, mI, size_N, size_N);	//배열을 파일에 출력하기
	printf(" mI: \n");
	printMtrx(mI, size_N, size_N);	//배열을 실행화면에 출력하기
	fprintf(fout, "\n");
	printf("\n");

	//동적 할당 해제
	for (int i = 0; i < size_N; i++)
	{
		free(mA[i]);
		free(mI[i]);
		free(inv_A[i]);
	}

	//동적 할당 해제
	free(mA);
	free(mI);
	free(inv_A);

	fclose(fin);	//파일 닫기
}
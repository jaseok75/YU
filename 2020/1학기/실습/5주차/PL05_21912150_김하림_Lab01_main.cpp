/**
 * 파일명: "PL05_21912150_김하림_Lab01_main.cpp"
 * 프로그램의 목적 및 기본 기능:
 * - 이 프로그램은 menu에서 한 가지를 선택하고,
 *   선택한 함수를 실행해 실행화면에 출력하고,
 *   파일을 생성해 파일에도 출력하는 프로그램이다.
 *
 * 프로그램 작성자: 김하림 (2020년 04월 19일),
 * 최종 Update: 2020년 04월 19일 (김하림).
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "Array.h"

#define ESC 0x1B
#define Data_Input_File "Data_input.txt"
#define Data_Output_File "Data_output.txt"

void arrayStatistics_basicArray(FILE* fout);
void arrayStatistics_externArray(FILE* fout);
void arrayStatistics_fileDataArray(FILE* fout);
void arrayStatistics_inputArray(FILE* fout);
void arrayStatistics_dyntArray(FILE* fout);

int main(int argc, char argv[])
{
	int num_data, data;
	double sum = 0.0, var, diff, sq_diff_sum = 0.0, avg, std_dev;
	char menu;
	FILE* fout;
	fout = fopen(Data_Output_File, "w");

	if (fout == NULL)	//파일이 생성되지 않았다면 종료
	{
		printf("Error in creation of %s !!\n", Data_Output_File);
		return -1;
	}

	while (1)	//어떤 것을 실행할지 고르기
	{
		printf("\nTest Array Handling (1: data_array; 2: extern_array; 3: data_file; 4: data_input; 5: dyn_array; Esc: terminate): ");
		menu = _getche();

		if (menu == ESC)
			break;

		switch (menu)
		{
		case '1':
			arrayStatistics_basicArray(fout);
			break;
		case '2':
			arrayStatistics_externArray(fout);
			break;
		case '3':
			arrayStatistics_fileDataArray(fout);
			break;
		case '4':
			arrayStatistics_inputArray(fout);
			break;
		case '5':
			arrayStatistics_dyntArray(fout);
			break;
		}
	}

	fclose(fout);
	return 0;
}

void arrayStatistics_basicArray(FILE* fout)	//menu에서 1을 눌렀을 때
{
	int num_data = 10;
	//int data_array[MAX_NUM_DATA] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int data_array[MAX_NUM_DATA] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	printf("\nArrayStatistics_basicArray .....\n");
	fprintf(fout, "\nArrayStatistics_basicArray .....\n");
	getArrayStatistics(data_array, num_data);	//실행화면에서 통계자료 출력
	fgetArrayStatistics(fout, data_array, num_data);	//생성한 파일에서 통계자료 출력
	printf("arrayStatistics_basicArray - completed. Result is also stored in output file.\n");
}

void arrayStatistics_externArray(FILE* fout)	//menu에서 2를 눌렀을 때
{
	int num_data = 0;
	extern int data_array[MAX_NUM_DATA];

	printf("\nArrayStatistics_externArray .....\n");
	fprintf(fout, "\nArrayStatistics_externArray .....\n");

	//외부 파일에 선언되어 있는 data_array[]의 데이터 원소들을 차례로 읽고
	//-1이 아닌 원소의 개수를 파악하여 num_data로 설정할 것.

	for (int i = 0; i < MAX_NUM_DATA; i++)	//외부 파일에 선언돼 있는 data_array[]의 배열의 수 세기
	{
		if (data_array[i] == -1)
			break;
		else
			num_data++;
	}

	getArrayStatistics(data_array, num_data);	//실행 화면에서 배열의 통계자료 출력
	fgetArrayStatistics(fout, data_array, num_data);	//생성한 파일에서 배열의 통계자료 출력
	printf("arrayStatistics_basicArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}

void arrayStatistics_fileDataArray(FILE* fout)	//menu에서 3을 눌렀을 때
{
	FILE* fin;
	int data, num_data = 0;
	int data_array[MAX_NUM_DATA] = { 0 };

	printf("\nArrayStatstics_fileDataArray .....\n");
	fprintf(fout, "\nArrayStatistics_fileDataArray .....\n");
	fin = fopen(Data_Input_File, "r");

	// 데이터 파일 입력 기능을 이곳에 구현할 것

	if (fin == NULL)	//파일 생성이 되지 않았을 때 종료
	{
		printf("Error in opening input data file!!\n");
		return;
	}

	while (fscanf(fin, "%d", &data) != EOF)	//fin파일에 적힌 것을 읽고 data를 data_array 배열에 넣기
	{
		if (data == -1)
		{
			break;
		}
		data_array[num_data] = data;
		num_data++;
	}

	fclose(fin);
	getArrayStatistics(data_array, num_data);	//실행화면에서 배열의 통계자료 출력
	fgetArrayStatistics(fout, data_array, num_data);	//생성한 파일에서 배열의 통계자료 출력
	printf("arrayStatistics_fileDataArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}

void arrayStatistics_inputArray(FILE* fout)	//menu 4을 눌렀을 때
{
	int num_data, data;
	int data_array[MAX_NUM_DATA] = { 0 };
	printf("\nArrayStatistics_inputArray .....\n");
	fprintf(fout, "\nArraySatistics_inputArray .....\n");
	printf("Please input the number of integers (less than %d) = ", MAX_NUM_DATA);
	scanf("%d", &num_data);	//키보드에서 입력받을 data의 수 입력받기
	printf("Input %d integer data : ", num_data);

	// 표준 입력장치 (keyboard)를 사용한 데이터 입력을 이곳에 구현할 것.

	for (int i = 0; i < num_data; i++)	//키보드에서 data 입력받아서 data_array에 넣기
	{
		scanf("%d", &data);
		data_array[i] = data;
	}

	getArrayStatistics(data_array, num_data);	//실행화면에서 배열의 통계자료 출력
	fgetArrayStatistics(fout, data_array, num_data);	//생성한 파일에서 배열의 통계자료 출력
	printf("arrayStatistics_inputArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}

void arrayStatistics_dyntArray(FILE* fout)	//menu에서 5를 눌렀을 때
{
	int num_data;
	int data_array[MAX_ARRAY_SIZE] = { 0 };	//배열의 수가 30000이하일 때 사용할 배열
	printf("\nArrayStatistics_dynArray .....\n");
	fprintf(fout, "\nArrayStatistics_dynArray .....\n");
	printf("Size of dynamic array = ");
	scanf("%d", &num_data);	//배열의 수 입력받기

	// 동적 배열 생성 및 중복되지 않는 난수 배열 생성 기능을 이곳에 구현할 것.

	if (num_data <= 30000)
	{
		genRandArray(data_array, num_data);	//랜덤 숫자 생성하기
		getArrayStatistics(data_array, num_data);	//실행화면에서 배열의 통계자료 출력
		fgetArrayStatistics(fout, data_array, num_data);	//생성한 파일에서 배열의 통계자료 출력
	}

	else   //보너스 항목
	{
		int* flag = 0;
		int* bonus_array = 0;	//배열의 수가 30000을 초과할 때 사용할 포인터

		bonus_array = genBigRandArray(num_data);	//bonus, 랜덤 숫자 생성하기
		getArrayStatistics(bonus_array, num_data);	//실행화면에서 배열의 통계자료 출력
		fgetArrayStatistics(fout, bonus_array, num_data);	//생성한 파일에서 배열의 통계자료 출력

		//동적 배열의 반환 기능을 이곳에 구현할 것.

		free(flag);	//동적 메모리 해제
		free(bonus_array);	//동적 메모리 해제
	}

	printf("arrayStatistics_dynArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}
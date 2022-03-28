/**
 * ���ϸ�: "PL05_21912150_���ϸ�_Lab01_main.cpp"
 * ���α׷��� ���� �� �⺻ ���:
 * - �� ���α׷��� menu���� �� ������ �����ϰ�,
 *   ������ �Լ��� ������ ����ȭ�鿡 ����ϰ�,
 *   ������ ������ ���Ͽ��� ����ϴ� ���α׷��̴�.
 *
 * ���α׷� �ۼ���: ���ϸ� (2020�� 04�� 19��),
 * ���� Update: 2020�� 04�� 19�� (���ϸ�).
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

	if (fout == NULL)	//������ �������� �ʾҴٸ� ����
	{
		printf("Error in creation of %s !!\n", Data_Output_File);
		return -1;
	}

	while (1)	//� ���� �������� ����
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

void arrayStatistics_basicArray(FILE* fout)	//menu���� 1�� ������ ��
{
	int num_data = 10;
	//int data_array[MAX_NUM_DATA] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int data_array[MAX_NUM_DATA] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	printf("\nArrayStatistics_basicArray .....\n");
	fprintf(fout, "\nArrayStatistics_basicArray .....\n");
	getArrayStatistics(data_array, num_data);	//����ȭ�鿡�� ����ڷ� ���
	fgetArrayStatistics(fout, data_array, num_data);	//������ ���Ͽ��� ����ڷ� ���
	printf("arrayStatistics_basicArray - completed. Result is also stored in output file.\n");
}

void arrayStatistics_externArray(FILE* fout)	//menu���� 2�� ������ ��
{
	int num_data = 0;
	extern int data_array[MAX_NUM_DATA];

	printf("\nArrayStatistics_externArray .....\n");
	fprintf(fout, "\nArrayStatistics_externArray .....\n");

	//�ܺ� ���Ͽ� ����Ǿ� �ִ� data_array[]�� ������ ���ҵ��� ���ʷ� �а�
	//-1�� �ƴ� ������ ������ �ľ��Ͽ� num_data�� ������ ��.

	for (int i = 0; i < MAX_NUM_DATA; i++)	//�ܺ� ���Ͽ� ����� �ִ� data_array[]�� �迭�� �� ����
	{
		if (data_array[i] == -1)
			break;
		else
			num_data++;
	}

	getArrayStatistics(data_array, num_data);	//���� ȭ�鿡�� �迭�� ����ڷ� ���
	fgetArrayStatistics(fout, data_array, num_data);	//������ ���Ͽ��� �迭�� ����ڷ� ���
	printf("arrayStatistics_basicArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}

void arrayStatistics_fileDataArray(FILE* fout)	//menu���� 3�� ������ ��
{
	FILE* fin;
	int data, num_data = 0;
	int data_array[MAX_NUM_DATA] = { 0 };

	printf("\nArrayStatstics_fileDataArray .....\n");
	fprintf(fout, "\nArrayStatistics_fileDataArray .....\n");
	fin = fopen(Data_Input_File, "r");

	// ������ ���� �Է� ����� �̰��� ������ ��

	if (fin == NULL)	//���� ������ ���� �ʾ��� �� ����
	{
		printf("Error in opening input data file!!\n");
		return;
	}

	while (fscanf(fin, "%d", &data) != EOF)	//fin���Ͽ� ���� ���� �а� data�� data_array �迭�� �ֱ�
	{
		if (data == -1)
		{
			break;
		}
		data_array[num_data] = data;
		num_data++;
	}

	fclose(fin);
	getArrayStatistics(data_array, num_data);	//����ȭ�鿡�� �迭�� ����ڷ� ���
	fgetArrayStatistics(fout, data_array, num_data);	//������ ���Ͽ��� �迭�� ����ڷ� ���
	printf("arrayStatistics_fileDataArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}

void arrayStatistics_inputArray(FILE* fout)	//menu 4�� ������ ��
{
	int num_data, data;
	int data_array[MAX_NUM_DATA] = { 0 };
	printf("\nArrayStatistics_inputArray .....\n");
	fprintf(fout, "\nArraySatistics_inputArray .....\n");
	printf("Please input the number of integers (less than %d) = ", MAX_NUM_DATA);
	scanf("%d", &num_data);	//Ű���忡�� �Է¹��� data�� �� �Է¹ޱ�
	printf("Input %d integer data : ", num_data);

	// ǥ�� �Է���ġ (keyboard)�� ����� ������ �Է��� �̰��� ������ ��.

	for (int i = 0; i < num_data; i++)	//Ű���忡�� data �Է¹޾Ƽ� data_array�� �ֱ�
	{
		scanf("%d", &data);
		data_array[i] = data;
	}

	getArrayStatistics(data_array, num_data);	//����ȭ�鿡�� �迭�� ����ڷ� ���
	fgetArrayStatistics(fout, data_array, num_data);	//������ ���Ͽ��� �迭�� ����ڷ� ���
	printf("arrayStatistics_inputArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}

void arrayStatistics_dyntArray(FILE* fout)	//menu���� 5�� ������ ��
{
	int num_data;
	int data_array[MAX_ARRAY_SIZE] = { 0 };	//�迭�� ���� 30000������ �� ����� �迭
	printf("\nArrayStatistics_dynArray .....\n");
	fprintf(fout, "\nArrayStatistics_dynArray .....\n");
	printf("Size of dynamic array = ");
	scanf("%d", &num_data);	//�迭�� �� �Է¹ޱ�

	// ���� �迭 ���� �� �ߺ����� �ʴ� ���� �迭 ���� ����� �̰��� ������ ��.

	if (num_data <= 30000)
	{
		genRandArray(data_array, num_data);	//���� ���� �����ϱ�
		getArrayStatistics(data_array, num_data);	//����ȭ�鿡�� �迭�� ����ڷ� ���
		fgetArrayStatistics(fout, data_array, num_data);	//������ ���Ͽ��� �迭�� ����ڷ� ���
	}

	else   //���ʽ� �׸�
	{
		int* flag = 0;
		int* bonus_array = 0;	//�迭�� ���� 30000�� �ʰ��� �� ����� ������

		bonus_array = genBigRandArray(num_data);	//bonus, ���� ���� �����ϱ�
		getArrayStatistics(bonus_array, num_data);	//����ȭ�鿡�� �迭�� ����ڷ� ���
		fgetArrayStatistics(fout, bonus_array, num_data);	//������ ���Ͽ��� �迭�� ����ڷ� ���

		//���� �迭�� ��ȯ ����� �̰��� ������ ��.

		free(flag);	//���� �޸� ����
		free(bonus_array);	//���� �޸� ����
	}

	printf("arrayStatistics_dynArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
}
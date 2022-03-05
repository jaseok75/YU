/**
 * ���ϸ� : "Homework05_21912150_���ϸ�_main.cpp"
 * ���α׷��� ���� �� �⺻ ���:
 * - �� ���α׷��� �迭�� ���� ���ڸ� �ְ�,
 *   �迭�� ���� ������� ���� ����ϴ� ���α׷��̴�.
 *
 * ���α׷� �ۼ���: ���ϸ� (2020�� 04�� 19��),
 * ���� Update: 2020�� 04�� 19�� (���ϸ�).
*/
/*main.cpp*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"

int main(void)
{
	int array[MAX_NUM_DATA];
	int size;
	FILE* fout;
	fout = fopen("array_output.txt", "w");

	if (fout == NULL)
	{
		printf("Error in creation of array_output.txt!!\n");
		return 0;
	}

	for (size = 50; size <= 500; size += 50)
	{
		genRandArray(array, size);
		printArraySample(array, size, 10);
		fprintArraySample(fout, array, size, 10);
	}

	fclose(fout);
}
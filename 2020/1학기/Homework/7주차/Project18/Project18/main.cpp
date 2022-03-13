/*
 * ���ϸ�: "PL07_21912150_���ϸ�_Lab07_main.cpp"
 * ���α׷��� ���� �� �⺻ ���:
 * - �� ���α׷��� 1000000 ~ 10000000�� ���� �迭�� ���� ����,
 *   ���� ����, ��� �м�, hyprid_quick_selection_sort �� ���� ����ϴ� ���α׷��̴�.
 *
 * ���α׷� �ۼ���: ���ϸ� (2020�� 04�� 30��),
 * ���� Update: 2020�� 04�� 30�� (���ϸ�).
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Array_Algorithms.h"

void main()
{
	int* bigRandArray;
	int min, max;
	double avg, var, std_dev;
	LARGE_INTEGER freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time;
	FILE* fout;

	fout = fopen("output.txt", "w");

	if (fout == NULL)
	{
		printf("Error in creation of output file (output.txt)!!\n");
		exit(-1);
	}
	srand((unsigned)time(NULL));

	QueryPerformanceFrequency(&freq);

	for (int array_size = 1000000; array_size <= 10000000; array_size += 1000000)
	{
		bigRandArray = (int*)calloc(sizeof(int), array_size);
		genBigRandArray(bigRandArray, array_size, - array_size / 2);	//���ڸ� �������� �迭�� ����

		fprintf(fout, "Generated big random number array (size: %d):\n", array_size);
		fprintBigArraySample(fout, bigRandArray, array_size, ITEMS_PER_LINE, NUM_SAMPLE_LINES);
		getArrayStatistics(bigRandArray, array_size, &min, &max, &avg, &var, &std_dev);	//����ڷ� ���
		fprintf(fout, "Num_elements: %7d, Min: %6d, Max: %6d, Avg: %10.3lf, Var: %10.3lf, Std_dev: %10.3lf\n", array_size, min, max, avg, var, std_dev);

		QueryPerformanceCounter(&t_before);	//���α׷� ���� �ð� Ȯ��
		hybrid_quick_selection_sort(bigRandArray, array_size);	//�迭�� ����
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time = ((double)t_diff / freq.QuadPart);

		fprintf(fout, "Hybrid_Quick_Selection Sort took %8.2f [millisecond] to sort %d integer array.\n", elapsed_time * 1000.0, array_size);
		printf("Hybrid_Quick_Selection Sort took %8.2f [millisecond] to sort %d integer array.\n", elapsed_time * 1000.0, array_size);
		//fprintf(fout, "After quick sorting: \n");
		//fprintBigArraySample(fout, bigRandArray, array_size, ITEMS_PER_LINE, NUM_SAMPLE_LINES);

		free(bigRandArray);	//���� �Ҵ� ����
	}
	fclose(fout);
}
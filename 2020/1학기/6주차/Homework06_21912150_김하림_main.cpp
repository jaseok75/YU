/**
 * ���ϸ�: "PL06_21912150_���ϸ�_Lab01_main.cpp"
 * ���α׷��� ���� �� �⺻ ���:
 * - �� ���α׷��� �ܾ� (���ڿ�) �迭�� �������� �� �� ������ �����ϰ�,
 *   ���� �ð��� �����ϰ� �̸� ����ȭ��� ���Ͽ� ����ϴ� ���α׷��̴�.
 *
 * ���α׷� �ۼ���: ���ϸ�(2020�� 04�� 24��),
 * ���� Update: 2020�� 04�� 24�� (���ϸ�).
 */
/* main.cpp */
/* Performance Analysis for Sorting Algorithms of Word Array */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include "WordArray.h"

int main()
{
	extern char words[][MAX_WORD_LEN];	//�ܺ� �迭
	LARGE_INTEGER freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time;
	FILE* fout;
	fout = fopen("output.txt", "w");	//���� ����

	if (fout == NULL)	//������ ����� �������� �ʾ��� �� ���α׷� ����
	{
		printf("Error in creation of output.txt file!!\n");
		exit(-1);
	}

	srand((unsigned)time(NULL));
	QueryPerformanceFrequency(&freq);

	printf("Performance Analysis of Sorting Algorithms\n");

	for (int num_words = 10000; num_words <= 100000; num_words += 10000)
	{
		printf("Word array(size: %7d): ", num_words);
		fprintf(fout, "\n=================================================\n");
		
		genRandWordArray(words, num_words);	//�迭 �ʱ�ȭ

		fprintf(fout, "Randomly generated Word Array (size: %d)\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);

		fprintf(fout, "\nQuick sorting for Word Array (size: %d) .....\n", num_words);
		QueryPerformanceCounter(&t_before);
		_quickSortWordArray(words, num_words, 0, num_words - 1, 0);	//�� ����
		QueryPerformanceCounter(&t_after);

		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time = ((double)t_diff / freq.QuadPart);	//in second
		fprintf(fout, "QuickSort_WordArray(size: %d) took %10.3lf [millisecond]\n", num_words, elapsed_time * 10000.0);
		printf("Quick_Sort (%10.3lf ms), ", elapsed_time * 10000.0);	//�� ���Ŀ� �ɸ� �ð� ���

		fprintf(fout, "\nAfter sorting word array (size: %d)\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);
		fprintf(fout, "\n");

		suffleWordArray(words, num_words);	//�迭 ���� �Լ�
		fprintf(fout, "Word Array (size: %d) after Suffling\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);

		fprintf(fout, "\nSelection sorting for Word Array (size: %d) .....\n", num_words);
		QueryPerformanceCounter(&t_before);
		selectionSortWordArray(words, num_words);	//���� ����
		QueryPerformanceCounter(&t_after);

		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time = ((double)t_diff / freq.QuadPart);	//in second

		fprintf(fout, "SelectionSort_WordArray(size: %d) took %10.3lf [millisecond]\n", num_words, elapsed_time * 1000.0);
		printf("Select_Sort (%10.3lf ms)\n", elapsed_time * 1000.0);	//���� ���Ŀ� �ɸ� �ð� ���
		
		fprintf(fout, "\nAfter sorting word array (size: %d)\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);
		fprintf(fout, "\n");
	}

	fclose(fout);
}
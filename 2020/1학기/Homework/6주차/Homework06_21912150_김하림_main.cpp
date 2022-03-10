/**
 * 파일명: "PL06_21912150_김하림_Lab01_main.cpp"
 * 프로그램의 목적 및 기본 기능:
 * - 이 프로그램은 단어 (문자열) 배열의 선택정렬 및 퀵 정렬을 구현하고,
 *   실행 시간을 측정하고 이를 실행화면과 파일에 출력하는 프로그램이다.
 *
 * 프로그램 작성자: 김하림(2020년 04월 24일),
 * 최종 Update: 2020년 04월 24일 (김하림).
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
	extern char words[][MAX_WORD_LEN];	//외부 배열
	LARGE_INTEGER freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time;
	FILE* fout;
	fout = fopen("output.txt", "w");	//파일 생성

	if (fout == NULL)	//파일이 제대로 생성되지 않았을 때 프로그램 종료
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
		
		genRandWordArray(words, num_words);	//배열 초기화

		fprintf(fout, "Randomly generated Word Array (size: %d)\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);

		fprintf(fout, "\nQuick sorting for Word Array (size: %d) .....\n", num_words);
		QueryPerformanceCounter(&t_before);
		_quickSortWordArray(words, num_words, 0, num_words - 1, 0);	//퀵 정렬
		QueryPerformanceCounter(&t_after);

		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time = ((double)t_diff / freq.QuadPart);	//in second
		fprintf(fout, "QuickSort_WordArray(size: %d) took %10.3lf [millisecond]\n", num_words, elapsed_time * 10000.0);
		printf("Quick_Sort (%10.3lf ms), ", elapsed_time * 10000.0);	//퀵 정렬에 걸린 시간 출력

		fprintf(fout, "\nAfter sorting word array (size: %d)\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);
		fprintf(fout, "\n");

		suffleWordArray(words, num_words);	//배열 섞는 함수
		fprintf(fout, "Word Array (size: %d) after Suffling\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);

		fprintf(fout, "\nSelection sorting for Word Array (size: %d) .....\n", num_words);
		QueryPerformanceCounter(&t_before);
		selectionSortWordArray(words, num_words);	//선택 정렬
		QueryPerformanceCounter(&t_after);

		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time = ((double)t_diff / freq.QuadPart);	//in second

		fprintf(fout, "SelectionSort_WordArray(size: %d) took %10.3lf [millisecond]\n", num_words, elapsed_time * 1000.0);
		printf("Select_Sort (%10.3lf ms)\n", elapsed_time * 1000.0);	//선택 정렬에 걸린 시간 출력
		
		fprintf(fout, "\nAfter sorting word array (size: %d)\n", num_words);
		fprintBigWordArray(fout, words, num_words, WORDS_PER_LINE, SAMPLE_LINES);
		fprintf(fout, "\n");
	}

	fclose(fout);
}
/*
 * 파일명: "PL07_21912150_김하림_Lab07_main.cpp"
 * 프로그램의 목적 및 기본 기능:
 * - 이 프로그램은 1000000 ~ 10000000개 정수 배열의 동적 생성,
 *   난수 생성, 통계 분석, hyprid_quick_selection_sort 및 파일 출력하는 프로그램이다.
 *
 * 프로그램 작성자: 김하림 (2020년 04월 30일),
 * 최종 Update: 2020년 04월 30일 (김하림).
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
		genBigRandArray(bigRandArray, array_size, - array_size / 2);	//숫자를 랜덤으로 배열에 저장

		fprintf(fout, "Generated big random number array (size: %d):\n", array_size);
		fprintBigArraySample(fout, bigRandArray, array_size, ITEMS_PER_LINE, NUM_SAMPLE_LINES);
		getArrayStatistics(bigRandArray, array_size, &min, &max, &avg, &var, &std_dev);	//통계자료 계산
		fprintf(fout, "Num_elements: %7d, Min: %6d, Max: %6d, Avg: %10.3lf, Var: %10.3lf, Std_dev: %10.3lf\n", array_size, min, max, avg, var, std_dev);

		QueryPerformanceCounter(&t_before);	//프로그램 실행 시간 확인
		hybrid_quick_selection_sort(bigRandArray, array_size);	//배열의 정렬
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time = ((double)t_diff / freq.QuadPart);

		fprintf(fout, "Hybrid_Quick_Selection Sort took %8.2f [millisecond] to sort %d integer array.\n", elapsed_time * 1000.0, array_size);
		printf("Hybrid_Quick_Selection Sort took %8.2f [millisecond] to sort %d integer array.\n", elapsed_time * 1000.0, array_size);
		//fprintf(fout, "After quick sorting: \n");
		//fprintBigArraySample(fout, bigRandArray, array_size, ITEMS_PER_LINE, NUM_SAMPLE_LINES);

		free(bigRandArray);	//동적 할당 해제
	}
	fclose(fout);
}
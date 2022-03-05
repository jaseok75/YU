/**
 * 파일명 : "Homework05_21912150_김하림_main.cpp"
 * 프로그램의 목적 및 기본 기능:
 * - 이 프로그램은 배열에 랜덤 숫자를 넣고,
 *   배열을 파일 입출력을 통해 출력하는 프로그램이다.
 *
 * 프로그램 작성자: 김하림 (2020년 04월 19일),
 * 최종 Update: 2020년 04월 19일 (김하림).
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
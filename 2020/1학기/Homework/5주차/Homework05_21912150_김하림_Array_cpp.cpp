#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"

void genRandArray(int array[], int size)	//중복되지 않는 정수형 난수 배열 생성 함수
{
	char* flag;
	unsigned int number;
	int count = 0;

	srand((unsigned)time(NULL));	//매번 다른 숫자 발생
	flag = (char*)malloc(sizeof(char) * size);	//flag 배열을 size만큼 동적 할당

	while (count < size)
	{
		number = rand() % size;	//랜덤 숫자 생성

		if (flag[number] == 1)	//랜덤 숫자 중복 방지
		{
			continue;
		}

		else   //랜덤 숫자가 중복이 아닐시 배열에 담기
		{
			flag[number] = 1;
			array[count++] = number;
		}
	}
}

void suffleArray(int array[], int size)	//배열에 포함돼 있는 정수 원소들의 위치를 섞는 함수
{
	int i1, i2, d;
	srand((unsigned)time(NULL));	//매번 다른 숫자를 생성하기 위함

	for (int i = 0; i < size / 2; i++)
	{
		i1 = rand() % size;	//배열의 자리를 랜덤으로 생성
		i2 = rand() % size;

		/* suffle array */
		d = array[i1];
		array[i1] = array[i2];
		array[i2] = d;
	}
}

void printArraySample(int array[], int size, int line_size)	//배열의 내용 출력 함수
{
	printf("Size of integer array = %d\n", size);

	if (size <= 50)	//배열의 크기가 50 이하일 때
	{
		for (int i = 0, count = 0; i < size; i++)	//배열을 한 줄에 10개씩 출력
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
			{
				printf("\n");
			}
		}
		printf("\n");
	}

	else   //배열의 크기가 50을 초과할 때
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//배열의 맨 첫 2줄 출력
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("....\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//배열의 맨 끝 2줄 출력
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("\n");
	}
}

void fprintArraySample(FILE* fout, int array[], int size, int line_size)	//배열의 내용을 파일에 출력하는 함수
{
	fprintf(fout, "Size of integer array = %d\n", size);

	if (size <= 50)	//배열의 크기가 50 이하일 때
	{
		for (int i = 0, count = 0; i < size; i++)	//배열을 한 줄에 10개씩 출력
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
			{
				fprintf(fout, "\n");
			}
		}
		fprintf(fout, "\n");
	}

	else   //배열의 크기가 50을 초과할 때
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//배열의 맨 첫 2줄 출력
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				fprintf(fout, "\n");
		}
		fprintf(fout, "....\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//배열의 맨 끝 2줄 출력
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				fprintf(fout, "\n");
		}
		fprintf(fout, "\n");
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"

void genRandArray(int array[], int size)	//�ߺ����� �ʴ� ������ ���� �迭 ���� �Լ�
{
	char* flag;
	unsigned int number;
	int count = 0;

	srand((unsigned)time(NULL));	//�Ź� �ٸ� ���� �߻�
	flag = (char*)malloc(sizeof(char) * size);	//flag �迭�� size��ŭ ���� �Ҵ�

	while (count < size)
	{
		number = rand() % size;	//���� ���� ����

		if (flag[number] == 1)	//���� ���� �ߺ� ����
		{
			continue;
		}

		else   //���� ���ڰ� �ߺ��� �ƴҽ� �迭�� ���
		{
			flag[number] = 1;
			array[count++] = number;
		}
	}
}

void suffleArray(int array[], int size)	//�迭�� ���Ե� �ִ� ���� ���ҵ��� ��ġ�� ���� �Լ�
{
	int i1, i2, d;
	srand((unsigned)time(NULL));	//�Ź� �ٸ� ���ڸ� �����ϱ� ����

	for (int i = 0; i < size / 2; i++)
	{
		i1 = rand() % size;	//�迭�� �ڸ��� �������� ����
		i2 = rand() % size;

		/* suffle array */
		d = array[i1];
		array[i1] = array[i2];
		array[i2] = d;
	}
}

void printArraySample(int array[], int size, int line_size)	//�迭�� ���� ��� �Լ�
{
	printf("Size of integer array = %d\n", size);

	if (size <= 50)	//�迭�� ũ�Ⱑ 50 ������ ��
	{
		for (int i = 0, count = 0; i < size; i++)	//�迭�� �� �ٿ� 10���� ���
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

	else   //�迭�� ũ�Ⱑ 50�� �ʰ��� ��
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//�迭�� �� ù 2�� ���
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("....\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//�迭�� �� �� 2�� ���
		{
			printf("%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				printf("\n");
		}
		printf("\n");
	}
}

void fprintArraySample(FILE* fout, int array[], int size, int line_size)	//�迭�� ������ ���Ͽ� ����ϴ� �Լ�
{
	fprintf(fout, "Size of integer array = %d\n", size);

	if (size <= 50)	//�迭�� ũ�Ⱑ 50 ������ ��
	{
		for (int i = 0, count = 0; i < size; i++)	//�迭�� �� �ٿ� 10���� ���
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

	else   //�迭�� ũ�Ⱑ 50�� �ʰ��� ��
	{
		for (int i = 0, count = 0; i < 2 * line_size; i++)	//�迭�� �� ù 2�� ���
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				fprintf(fout, "\n");
		}
		fprintf(fout, "....\n");

		for (int i = size - (2 * line_size), count = 0; i < size; i++)	//�迭�� �� �� 2�� ���
		{
			fprintf(fout, "%5d ", array[i]);
			count++;

			if (count % line_size == 0)
				fprintf(fout, "\n");
		}
		fprintf(fout, "\n");
	}
}
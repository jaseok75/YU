/*
 * ���ϸ�: "Homework10.cpp"
 *���α׷��� ���� �� �⺻ ���:
 * - �� ���α׷��� �����ڸ� ó���ϴ� ���α׷��̴�.
 *
 * ���α׷� �ۼ���: ���ϸ�(2020�� 06�� 01��),
 *���� Update: 2020�� 06�� 01��(���ϸ�).
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 50
#define NUM_WORDS 100

void stringSort(char** words, int num_words, int max_word_len);

int main()
{
	FILE* pFin = NULL;
	FILE* pFout = NULL;

	char word[80];
	char words[NUM_WORDS][MAX_WORD_LEN];
	char** wordList;
	int word_len[MAX_WORD_LEN];
	int word_count;

	//������ �б� ���� ����
	pFin = fopen("words_input.txt", "r");

	//������ ����� ������ �ʾҴٸ� ����
	if (pFin == NULL)
	{
		printf("Error in input data file open!!\n");
		return 0;
	}

	//������ ���� ���� ����
	pFout = fopen("words_output.txt", "w");

	//������ ����� ������ �ʾҴٸ� ����
	if (pFout == NULL)
	{
		printf("Error in output data file creation !!\n");
		return 0;
	}

	word_count = 0;

	//���Ͽ��� �ܾ� �о�ͼ� �迭�� ����
	while (fscanf(pFin, "%s", word) != EOF)
	{
		printf("%2d-th input word: %s\n", word_count, word);
		strcpy(words[word_count], word);
		word_len[word_count] = strlen(words[word_count]);
		word_count++;
	}

	printf("Number of words: %d\n", word_count);
	wordList = (char**)calloc(sizeof(char*), word_count);	//�ܾ ������ ���� �迭 ���� �Ҵ��ϱ�

	for (int i = 0; i < word_count; i++)
	{
		fprintf(pFout, "(%2d)th-word : %s\t\t(word_length: %d)\n", i, words[i], word_len[i]);
		wordList[i] = (char*)calloc(sizeof(char), word_len[i]);
		strcpy(wordList[i], words[i]);
	}

	stringSort(wordList, word_count, MAX_WORD_LEN);	//�ܾ� �����ϱ�

	fprintf(pFout, "Sorted word list:\n");

	//������ �ܾ� �迭 ���Ͽ� ����ϱ�
	for (int i = 0; i < word_count; i++)
	{
		fprintf(pFout, "%s\t", wordList[i]);
		if (i % 5 == 4)
		{
			fprintf(pFout, "\n");
		}
	}

	fprintf(pFout, "\n");
	fclose(pFin);
	fclose(pFout);
}

//�ܾ� �迭�� �����ϴ� �Լ�
void stringSort(char** words, int num_words, int max_word_len)
{
	char* temp_word;
	int i, j, min;
	temp_word = (char*)calloc(sizeof(char), max_word_len);	//���� �Ҵ�

	if (temp_word == NULL)
	{
		printf("Error in dynamic allocation of memory for temp_word !!\n");
		exit;
	}

	/* selection sorting of words */

	//�����ϱ�
	for (i = 0; i < num_words; i++)
	{
		strcpy(temp_word, words[i]);
		min = i;

		for (j = i + 1; j < num_words; j++)
		{
			if (strcmp(temp_word, words[j]) > 0)
			{
				min = j;
				strcpy(temp_word, words[j]);
			}
		}

		if (min != i)
		{
			/* temp_word contains words[min] already !!*/
			strcpy(words[min], words[i]);
			strcpy(words[i], temp_word);
		}
	}

	free(temp_word);	//���� �Ҵ� ����
}
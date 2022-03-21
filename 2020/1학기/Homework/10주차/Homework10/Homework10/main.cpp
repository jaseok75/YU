/*
 * 파일명: "Homework10.cpp"
 *프로그램의 목적 및 기본 기능:
 * - 이 프로그램은 영문자를 처리하는 프로그램이다.
 *
 * 프로그램 작성자: 김하림(2020년 06월 01일),
 *최종 Update: 2020년 06월 01일(김하림).
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

	//파일을 읽기 모드로 열기
	pFin = fopen("words_input.txt", "r");

	//파일이 제대로 열리지 않았다면 중지
	if (pFin == NULL)
	{
		printf("Error in input data file open!!\n");
		return 0;
	}

	//파일을 쓰기 모드로 열기
	pFout = fopen("words_output.txt", "w");

	//파일이 제대로 열리지 않았다면 중지
	if (pFout == NULL)
	{
		printf("Error in output data file creation !!\n");
		return 0;
	}

	word_count = 0;

	//파일에서 단어 읽어와서 배열에 저장
	while (fscanf(pFin, "%s", word) != EOF)
	{
		printf("%2d-th input word: %s\n", word_count, word);
		strcpy(words[word_count], word);
		word_len[word_count] = strlen(words[word_count]);
		word_count++;
	}

	printf("Number of words: %d\n", word_count);
	wordList = (char**)calloc(sizeof(char*), word_count);	//단어를 정렬해 담을 배열 동적 할당하기

	for (int i = 0; i < word_count; i++)
	{
		fprintf(pFout, "(%2d)th-word : %s\t\t(word_length: %d)\n", i, words[i], word_len[i]);
		wordList[i] = (char*)calloc(sizeof(char), word_len[i]);
		strcpy(wordList[i], words[i]);
	}

	stringSort(wordList, word_count, MAX_WORD_LEN);	//단어 정렬하기

	fprintf(pFout, "Sorted word list:\n");

	//정렬한 단어 배열 파일에 출력하기
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

//단어 배열을 정렬하는 함수
void stringSort(char** words, int num_words, int max_word_len)
{
	char* temp_word;
	int i, j, min;
	temp_word = (char*)calloc(sizeof(char), max_word_len);	//동적 할당

	if (temp_word == NULL)
	{
		printf("Error in dynamic allocation of memory for temp_word !!\n");
		exit;
	}

	/* selection sorting of words */

	//정렬하기
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

	free(temp_word);	//동적 할당 해제
}
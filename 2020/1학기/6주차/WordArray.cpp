/* WordArray.cpp */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "WordArray.h"

void genWord(char word[], int min_word_len, int max_word_len)	//�迭 �ȿ� ���ڿ��� �������� ������ ����
{
	int length;
	int term = max_word_len - min_word_len;	//���ڿ��� ������ ����

	length = rand() % term + min_word_len;	//���ڿ��� ���̸� �������� ����

	word[0] = rand() % NUM_ALPHABET + 'A';	//���ڿ� �� ù ��° ���ڴ� �빮�ڷ� ����

	for (int i = 1; i < length; i++)	//�� ��° ���ں��� �������� �ҹ��� ����
	{
		word[i] = rand() % NUM_ALPHABET + 'a';
	}
	word[length] = '\0';	//���ڿ��� �������� '\0'�� ����
}

void genRandWordArray(char wordArray[][MAX_WORD_LEN], int size)	// ���ڿ��� size��ŭ �������� �����ϴ� �Լ�
{
	for (int i = 0; i < size; i++)
	{
		genWord(wordArray[i], MIN_WORD_LEN, MAX_WORD_LEN);
	}
}

// ���ڿ� �迭�� ���Ͽ� ����ϴ� �Լ�
void fprintBigWordArray(FILE* fout, char wordList[][MAX_WORD_LEN], int num_words, int words_per_line, int sample_lines)
{
	//�迭�� �պκ� sample_lines * words_per_line����ŭ ���
	for (int i = 0, count = 0; i < sample_lines * words_per_line; i++)
	{
		fprintf(fout, "%-15s\t", wordList[i]);
		count++;

		if (count % words_per_line == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "....\n");

	//�迭�� �޺κ� sample_lines * words_per_line����ŭ ���
	for (int i = num_words - (sample_lines * words_per_line), count = 0; i < num_words; i++)
	{
		fprintf(fout, "%-15s\t", wordList[i]);
		count++;

		if (count % words_per_line == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "\n");
}

// ���ڿ� �迭�� ���� �����ϴ� �Լ�
void selectionSortWordArray(char word[][MAX_WORD_LEN], int num_words)
{
	int min_pos;
	char temp[MAX_WORD_LEN];

	for (int pos = 0; pos < num_words; pos++)
	{
		min_pos = pos;

		for (int j = pos + 1; j < num_words; j++)
		{
			if (strcmp(word[min_pos], word[j]) > 0)
				min_pos = j;
		}
		if (min_pos != pos)
		{
			//word[min_pos]�� word[pos]�� �ڸ��� �ٲ۴�.
			strcpy(temp, word[min_pos]);
			strcpy(word[min_pos], word[pos]);
			strcpy(word[pos], temp);
		}
	}
}

//���ڿ� �迭�� �� �����ϴ� �Լ�(1)
int partitionWordArray(char wordArray[][MAX_WORD_LEN], int size, int left, int right, int pivotIndex, int level)
{
	char tempWord[MAX_WORD_LEN];
	char pivotValue[MAX_WORD_LEN];
	int newPI;	//new pivot index
	int i;

	strcpy(pivotValue, wordArray[pivotIndex]);

	//wordArray[pivotIndex]�� wordArray[right]�� �ٲ۴�.
	strcpy(tempWord, wordArray[pivotIndex]);
	strcpy(wordArray[pivotIndex], wordArray[right]);
	strcpy(wordArray[right], tempWord);	//Move pivot to end

	newPI = left;

	for (i = left; i <= (right - 1); i++)
	{
		if (strcmp(wordArray[i], pivotValue) <= 0)
		{
			//wordArray[i]�� [wordArray[newPI]�� �ڸ��� �ٲ۴�.
			strcpy(tempWord, wordArray[i]);
			strcpy(wordArray[i], wordArray[newPI]);
			strcpy(wordArray[newPI], tempWord);
			newPI = newPI + 1;
		}
	}

	// swap array[newPI] and array[right];
	strcpy(tempWord, wordArray[newPI]);
	strcpy(wordArray[newPI], wordArray[right]);
	strcpy(wordArray[right], tempWord);	//Move pivot to its final place

	return newPI;
}

//���ڿ� �迭�� �� �����ϴ� �Լ�(2)
void quickSortWordArray(char word[][MAX_WORD_LEN], int num_words)
{
	_quickSortWordArray(word, num_words, 0, num_words - 1, 0);
}

//���ڿ� �迭�� �� �����ϴ� �Լ�(3)
void _quickSortWordArray(char word[][MAX_WORD_LEN], int num_words, int left, int right, int level)
{
	int pI, newPI;	//pivot index

	if (left >= right)
	{
		return;
	}

	else if (left < right)
	{
		pI = left + (right - left) / 2;
	}

	newPI = partitionWordArray(word, num_words, left, right, pI, level);
	// element at newPivotIndex (newPI) is now at its final position

	if (left < (newPI - 1))
	{
		_quickSortWordArray(word, num_words, left, newPI - 1, level + 1);
		// recursively sort elements on the left of pivotNewIndex
	}

	if ((newPI + 1) < right)
	{
		_quickSortWordArray(word, num_words, newPI + 1, right, level + 1);
		// recursively sort elements on the right of pivotNewIndex
	}
}

// �迭�� ������ ���� �Լ�
void suffleWordArray(char wordArray[][MAX_WORD_LEN], int size)
{
	int i1, i2;
	char ch[MAX_WORD_LEN];
	srand((unsigned)time(NULL));

	for (int i = 0; i < size / 2; i++)
	{
		i1 = rand() % size;
		i2 = rand() % size;

		// wordArray[i1]�� wordArray[i2]�� �ڸ��� �ٲ۴�.
		strcpy(ch, wordArray[i1]);
		strcpy(wordArray[i1], wordArray[i2]);
		strcpy(wordArray[i2], ch);
	}
}
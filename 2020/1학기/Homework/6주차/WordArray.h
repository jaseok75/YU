/* WordArray.h */
#ifndef WORDARRAY_H
#define WORDARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#define MAX_WORD_LEN 15
#define MIN_WORD_LEN 5
#define MAX_NUM_WORDS 500000
#define NUM_ALPHABET 26
#define WORDS_PER_LINE 10
#define SAMPLE_LINES 5

void genWord(char word[], int min_word_len, int max_word_len);
void genRandWordArray(char wordArray[][MAX_WORD_LEN], int size);
void fprintBigWordArray(FILE* fout, char wordList[][MAX_WORD_LEN], int num_words, int words_per_line, int sample_lines);
void suffleWordArray(char wordArray[][MAX_WORD_LEN], int size);
void selectionSortWordArray(char wordArray[][MAX_WORD_LEN], int size);
int partitionWordArray(char wordArray[][MAX_WORD_LEN], int size, int left, int right, int pivotIndex, int level);
void quickSortWordArray(char word[][MAX_WORD_LEN], int num_words);
void _quickSortWordArray(char wordArray[][MAX_WORD_LEN], int num_words, int left, int right, int level);

#endif
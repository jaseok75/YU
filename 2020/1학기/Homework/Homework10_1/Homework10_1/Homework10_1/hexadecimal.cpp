#define _CRT_SECURE_NO_WARNINGS
#include "hexadecimal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int atox(char* hxdStr)
{
	unsigned char uc, hexChar;
	unsigned int hexVal = 0, hexSum = 0;

	for (int i = 0; i < MAX_HEX_STR_LEN; i++)
	{
		hexChar = hxdStr[i];

		if (hexChar == NULL)
			break;

		if ((hexChar >= '0') && (hexChar <= '9'))
			hexVal = hexChar - '0';

		else if ((hexChar >= 'A') && (hexChar <= 'F'))
			hexVal = hexChar - 'A' + 10;

		else if ((hexChar >= 'a') && (hexChar <= 'f'))
			hexVal = hexChar - 'a' + 10;

		else
		{
			printf("Error in atox() :: given hxdStr (%x) is not hex code character !!\n", hexChar);
			continue;
		}
		hexSum = hexSum * 16 + hexVal;
	}
	return hexSum;
}

void xtoa(char* strBuf, int hxd)
{
	unsigned int hexVal = 0;
	unsigned int count = 0;
	unsigned int number = 0;
	char* strStr;

	strStr = (char*)calloc(MAX_HEX_STR_LEN, sizeof(char));  //동적 할당


	count = (unsigned int)hxd;

	// 16진수를 문자로 변환
	for (int i = 0; i < MAX_HEX_STR_LEN; i++)
	{
		hexVal = count % 16;
		count /= 16;

		if ((hexVal >= 0) && (hexVal <= 9))
			strStr[i] = hexVal + '0';

		else if ((hexVal >= 10) && (hexVal <= 15))
			strStr[i] = hexVal + 'A' - 10;

		else
			continue;

		if (count == 0)
			break;
	}

	// 문자열을 역순으로 다시 저장
	for (int i = 0; i < strlen(strStr); i++)
	{
		strBuf[strlen(strStr) - i - 1] = strStr[i];
	}
}
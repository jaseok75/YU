#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hexadecimal.h"

void main()
{
	char* hexStr;
	char* hexConverStr;
	unsigned int value_int;

	while (1)
	{
		hexStr = (char*)calloc(MAX_HEX_STR_LEN, sizeof(char));
		hexConverStr = (char*)calloc(MAX_HEX_STR_LEN, sizeof(char));
		printf("input hexadecimal number : ");
		scanf("%s", hexStr);

		if (strcmp(hexStr, ".") == 0)
			break;

		value_int = atox(hexStr);
		printf("hexadecimal (%s) = %d (decimal)\n", hexStr, value_int);
		xtoa(hexConverStr, value_int);
		printf("hexadecimal (%s) = %d (decimal) = %#0X (hexadecimal) = re-converted hexadecimal string (%s)\n", hexStr, value_int, value_int, hexConverStr);
	}

	free(hexStr);
	free(hexConverStr);
}
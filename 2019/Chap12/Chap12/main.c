//정보통신공학과 21912150 김하림
/*
* Project: Chap12
* Date: 2019.11.30.
* Content: 수식을 문자열로 입력 받아 계산하는 프로그램을 작성하시오.
* - 제한사항 1: 연산은 사칙 연산 (+, -, *, /)으로만 한정함.
* - 제한사항 2: 입력하는 숫자는 double형으로 가정.
* - 제한사항 3: 한 줄 당 연산의 개수: 0, 1개.
* - 제한사항 4: 숫자와 연산 기호 사이에는 공백이 있을 수도 있고, 없을 수도 있음.
*/
#include <stdio.h>

double f_number(int start, char str[])	//문자열을 숫자로 변환하는 함수
{
	int point = 0;
	int j = start;
	int f_start = 0;
	int k = 0;
	double minus = 1;
	double answer_first = 0;
	double answer_last = 0;
	double answer = 0;

	while (1)
	{
		if (str[j] >= '0' && str[j] <= '9')	//문자열이 숫자라면
			break;
		else
			f_start++;	//시작부분이 숫자가 아닌 형태라면 시작부분을 +1하기

		j++;	//문자열이 숫자가 나올 때까지 반복
	}

	j = start + f_start;	//j초기화

	while (1)
	{
		if (str[j] == '.')	//문자열에 소수점이 있다면
		{
			point = j;	//소수점이 있는 칸의 번호 저장
			break;
		}

		if (str[j] <= '0' || str[j] >= '9')	//문자열이 숫자가 아닌 부분이면
			break;

		j++;	//문자열에 소수점이 있거나 문자열이 숫자가 아닌 부분이 나올 때까지 반복
	}

	j = start;	//j초기화
	f_start = 0;	//f_start초기화

	if (point != 0)	//문자열이 소수라면
	{
		while (1)	//문자열의 시작점 숫자로 맞춰주기
		{
			if (str[j] >= '0' && str[j] <= '9')
				break;
			else
				f_start++;

			j++;
		}
		for (j = start + f_start; j < point - 1; j++)
		{
			answer_first += ((int)str[j] - '0');	//문자열(문자 형태이므로 '0'만큼 빼준다)을 소수점 앞부분에 더한다.
			answer_first *= 10;
		}

		answer_first += ((int)str[point - 1] - '0');	//맨 뒤의 숫자에도 10을 곱해줬기 때문에 마지막 것은 나눠준다.

		for (j = point + 1; str[j] >= '0' && str[j] <= '9'; j++)
		{
			minus *= 0.1;	//소수점 뒷부분의 자릿수를 맞춰주기 위한 변수
			answer_last += ((int)str[j] - '0') * minus;	//문자열(문자 형태이크로 '0'만큼 빼준다)을 자릿수를 맞춘 후 소수점 뒷부분에 더한다.
		}
	}

	else	//문자열이 정수라면
	{
		while (1)	//문자열의 시작점 숫자로 맞춰주기
		{
			if (str[j] >= '0' && str[j] <= '9')
				break;
			else
				f_start++;

			j++;
		}
		for (j = start + f_start; str[j] >= '0' && str[j] <= '9'; j++)
		{
			answer_first += ((int)str[j] - '0');	//answer는 밑에서 다시 계산해주기 때문에 answer_first에 숫자를 더한다.
			answer_first *= 10;	//자릿수 맞춰주기
		}

		answer_first /= 10;	//마지막 곱해준 10다시 나눠주기
	}

	answer = answer_first + answer_last;	//위에서 계산한 first부분과 last부분 합쳐주기
	return answer;
}

double f_result(int i, double number_1, double number_2, char str[])	//연산 계산하는 함수
{
	double result = 0;

	if (str[i] == '+')	// +계산
	{
		result = number_1 + number_2;
	}

	else if (str[i] == '-')	//-계산
	{
		result = number_1 - number_2;
	}

	else if (str[i] == '*')	//*계산
	{
		result = number_1 * number_2;
	}

	else if (str[i] == '/')	//나누기 계산
	{
		result = number_1 / number_2;
	}

	return result;	//결과값 반환
}

int main(void)
{
	char str[100];	//수식을 입력받을 문자열
	int i = 0;
	int j = 0;
	double number_1 = 0;
	double number_2 = 0;
	double result = 0;

	printf("수식을 입력하시오 (예: 2 * 5):\n");
	gets_s(str, 100);	//수식을 공백을 포함하게 입력받기

	for (i = 0; i < 100; i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')	//수식에 연산기호가 있다면
		{
			number_1 = f_number(0, str);	//연산기호 앞까지를 숫자로 변환
			number_2 = f_number(i + 1, str);	//연산기호 뒷부분을 숫자로 변환
			result = f_result(i, number_1, number_2, str);	//결과 계산

			printf("Result = %.03lf", result);
			return 0;
		}
	}

	//수식에 연산자가 없었다면(앞부분의 return 0을 해결하지 못하고 밑으로 내려옴)
	number_1 = f_number(0, str);	//수식을 전부 숫자로 변환
	printf("Result = %.03lf", number_1);

	return 0;
}
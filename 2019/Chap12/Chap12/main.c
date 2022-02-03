//������Ű��а� 21912150 ���ϸ�
/*
* Project: Chap12
* Date: 2019.11.30.
* Content: ������ ���ڿ��� �Է� �޾� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* - ���ѻ��� 1: ������ ��Ģ ���� (+, -, *, /)���θ� ������.
* - ���ѻ��� 2: �Է��ϴ� ���ڴ� double������ ����.
* - ���ѻ��� 3: �� �� �� ������ ����: 0, 1��.
* - ���ѻ��� 4: ���ڿ� ���� ��ȣ ���̿��� ������ ���� ���� �ְ�, ���� ���� ����.
*/
#include <stdio.h>

double f_number(int start, char str[])	//���ڿ��� ���ڷ� ��ȯ�ϴ� �Լ�
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
		if (str[j] >= '0' && str[j] <= '9')	//���ڿ��� ���ڶ��
			break;
		else
			f_start++;	//���ۺκ��� ���ڰ� �ƴ� ���¶�� ���ۺκ��� +1�ϱ�

		j++;	//���ڿ��� ���ڰ� ���� ������ �ݺ�
	}

	j = start + f_start;	//j�ʱ�ȭ

	while (1)
	{
		if (str[j] == '.')	//���ڿ��� �Ҽ����� �ִٸ�
		{
			point = j;	//�Ҽ����� �ִ� ĭ�� ��ȣ ����
			break;
		}

		if (str[j] <= '0' || str[j] >= '9')	//���ڿ��� ���ڰ� �ƴ� �κ��̸�
			break;

		j++;	//���ڿ��� �Ҽ����� �ְų� ���ڿ��� ���ڰ� �ƴ� �κ��� ���� ������ �ݺ�
	}

	j = start;	//j�ʱ�ȭ
	f_start = 0;	//f_start�ʱ�ȭ

	if (point != 0)	//���ڿ��� �Ҽ����
	{
		while (1)	//���ڿ��� ������ ���ڷ� �����ֱ�
		{
			if (str[j] >= '0' && str[j] <= '9')
				break;
			else
				f_start++;

			j++;
		}
		for (j = start + f_start; j < point - 1; j++)
		{
			answer_first += ((int)str[j] - '0');	//���ڿ�(���� �����̹Ƿ� '0'��ŭ ���ش�)�� �Ҽ��� �պκп� ���Ѵ�.
			answer_first *= 10;
		}

		answer_first += ((int)str[point - 1] - '0');	//�� ���� ���ڿ��� 10�� ������� ������ ������ ���� �����ش�.

		for (j = point + 1; str[j] >= '0' && str[j] <= '9'; j++)
		{
			minus *= 0.1;	//�Ҽ��� �޺κ��� �ڸ����� �����ֱ� ���� ����
			answer_last += ((int)str[j] - '0') * minus;	//���ڿ�(���� ������ũ�� '0'��ŭ ���ش�)�� �ڸ����� ���� �� �Ҽ��� �޺κп� ���Ѵ�.
		}
	}

	else	//���ڿ��� �������
	{
		while (1)	//���ڿ��� ������ ���ڷ� �����ֱ�
		{
			if (str[j] >= '0' && str[j] <= '9')
				break;
			else
				f_start++;

			j++;
		}
		for (j = start + f_start; str[j] >= '0' && str[j] <= '9'; j++)
		{
			answer_first += ((int)str[j] - '0');	//answer�� �ؿ��� �ٽ� ������ֱ� ������ answer_first�� ���ڸ� ���Ѵ�.
			answer_first *= 10;	//�ڸ��� �����ֱ�
		}

		answer_first /= 10;	//������ ������ 10�ٽ� �����ֱ�
	}

	answer = answer_first + answer_last;	//������ ����� first�κа� last�κ� �����ֱ�
	return answer;
}

double f_result(int i, double number_1, double number_2, char str[])	//���� ����ϴ� �Լ�
{
	double result = 0;

	if (str[i] == '+')	// +���
	{
		result = number_1 + number_2;
	}

	else if (str[i] == '-')	//-���
	{
		result = number_1 - number_2;
	}

	else if (str[i] == '*')	//*���
	{
		result = number_1 * number_2;
	}

	else if (str[i] == '/')	//������ ���
	{
		result = number_1 / number_2;
	}

	return result;	//����� ��ȯ
}

int main(void)
{
	char str[100];	//������ �Է¹��� ���ڿ�
	int i = 0;
	int j = 0;
	double number_1 = 0;
	double number_2 = 0;
	double result = 0;

	printf("������ �Է��Ͻÿ� (��: 2 * 5):\n");
	gets_s(str, 100);	//������ ������ �����ϰ� �Է¹ޱ�

	for (i = 0; i < 100; i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')	//���Ŀ� �����ȣ�� �ִٸ�
		{
			number_1 = f_number(0, str);	//�����ȣ �ձ����� ���ڷ� ��ȯ
			number_2 = f_number(i + 1, str);	//�����ȣ �޺κ��� ���ڷ� ��ȯ
			result = f_result(i, number_1, number_2, str);	//��� ���

			printf("Result = %.03lf", result);
			return 0;
		}
	}

	//���Ŀ� �����ڰ� �����ٸ�(�պκ��� return 0�� �ذ����� ���ϰ� ������ ������)
	number_1 = f_number(0, str);	//������ ���� ���ڷ� ��ȯ
	printf("Result = %.03lf", number_1);

	return 0;
}
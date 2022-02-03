/*
* Project: Chap11
* Date: 2019.11.12.
* Contect: ȭ�鿡 ��ǥ�� 5���� �������� ǥ���ϰ�, ��ź�� ��Ƽ� ���ߴ� ���� ���α׷��� �ۼ��Ͻÿ�.
* - ��ź�� ������ 5���̰�, �Ź� �߻� ������ �Է¹޴´�.
* - ������ ������ 100�� ȹ��
* - main() �Լ������� �ð� t���� ��ź�� ��ġ (x, y)�� ����ϰ�, ������ ���� ������ �Լ��� ȣ���Ͽ� ȭ�鿡 ��ź�� ǥ���Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h> //cls �Լ��� ����ϱ� ���� ���̺귯��
#include <math.h> //sin�Լ�, cos�Լ��� ����ϱ� ���� ���̺귯��
#include <windows.h> //sleep�Լ��� ����ϱ� ���� ���̺귯��
#include <time.h> //srand((unsigned)time(NULL)) ����� ���� ���̺귯��
#define ROWS 25 //������ ĭ ��
#define COLUMNS 80 //������ ĭ ��
int shells = 5; //�������� -> ��ź�� ���� ��
int score = 0; //�������� -> ���� ����

/*��ź = 1
  �ƹ��͵� ���� = 0
  ��ǥ�� = 3
  ��ź�� ���� ��ǥ�� = 4*/

void print_shell(int matrix[ROWS][COLUMNS]) //ȭ���� ��Ÿ�� �Լ�
{
	int i;
	int j;

	for (i = 0; i < ROWS i++)
	{
		for (j = 0; j < COLUMNS j++)
		{
			if (matrix[i][j] == 0) //�迭�� ���� 0�̸�
			{
				printf(" "); //�ƹ��͵� ǥ������ �ʴ´�.
			}

			else if (matrix[i][j] == 3) //�迭�� ���� 3�̸�
			{
				printf("#"); //��ǥ���� '#'ǥ��
			}

			else if (matrix[i][j] == 4) //�迭�� ���� 4�̸�
			{
				printf("H"); //���� ��ź�� 'H'ǥ��
			}

			else if (matrix[i][j] == 1) //�迭�� ���� 1�̸�
			{
				printf("*"); //��ź�� '*'ǥ��
			}
		}
		printf("\n");
	}

	for (i = 0; i < COLUMNS i++)//�ٴ��� ǥ���ϴ� �ݺ���
	{
		printf("=");//COLUMNS�� '='�� ���
	}

	printf("\n");

	printf("Bullets = %d                     ", shells); //���� ��ź�� �� ���
	printf("Score: %d\n", score); //���� ���� ���
}


int main(void)
{
	srand((unsigned)time(NULL)); //������ ������ �޶����� �ϱ� ����
	int x = 0; //������ ����(�迭�� ĭ ���̱� ������ �������̴�)
	int y = 0; //������ ����(�迭�� ĭ ���̱� ������ �������̴�)
	double degree = 0; //��ź�� ���� ����
	double t = 0; //�ð�
	int matrix[ROWS][COLUMNS] = { 0, }; //���� 80, ���� 25ĭ�� �迭
	int i;
	int j;

	for (i = 0; i < 5; i++) //��ǥ���� ���� 5��
	{
		matrix[rand() % (ROWS - 1)][rand() % COLUMNS] = 3; //����(0�̻�, 24�̸��� ���� ��), ����(0�̻�, 80�̸��� ���� ��) ĭ�� 3 ����
	}

	while (shells > 0) //��ź�� ����������
	{
		degree = 0; //�ݺ��� ������ ���� �ʱ�ȭ
		t = 0; //�ݺ��� ������ �ð� �ʱ�ȭ

		for (i = 0; i < COLUMNS i++)
		{
			if (matrix[ROWS - y][x] == 4)
			{
				matrix[ROWS - y][x] = 0; //�迭�� ���� 4�϶��� �ʱ�ȭ�� ���� �ʰ� �Ѿ�� ������ �ݺ��� �� �ʱ�ȭ
			}
			matrix[ROWS - 1][0] = 1; //��ź�� ������
		}

		print_shell(matrix); //ȭ���� ǥ��(print_shell�Լ� ȣ��)

		printf("�߻� ������ �Է��Ͻÿ�(degree, 0 ~ 90):");
		scanf("%lf", &degree); //���ϴ� ���� �Է�
		shells -= 1; //��ź�� �� �� �� ����

		degree = degree * 3.14 / 180; //������ �������� �ٲٱ�

		for (i = 0; i < ROWS i++)
		{
			for (j = 0; j < COLUMNS j++)
			{
				x = 20 * cos(degree) * t; //x��ġ
				y = 20 * sin(degree) * t - (9.8 * (t * t) / 2) + 1; //y��ġ

				matrix[ROWS - 2][0] = 0; //������ ǥ���� �� �� ���ֱ�

				if (matrix[ROWS - y][x] == 3) //��� ���� ��ǥ���� ��ġ�� ��� ���� ������(���� ��ź�� ��ǥ���� �¾Ҵٸ�)
				{
					matrix[ROWS - y][x] = 4; //���� �� ����
				}

				else //���� ��ź�� ��ǥ���� ���� �ʾҴٸ�
				{
					matrix[ROWS - y][x] = 1; //�迭�� ��ź�� �� ����
				}

				if (x >= 0 && y >= 1)
				{
					system("cls"); //ȭ�鿡 ������ ������� �ϴ� �Լ�
					print_shell(matrix); //ȭ���� ǥ��(print_shell�Լ� ȣ��)
					Sleep(100); //���α׷��� ���� �ӵ��� 0.1�� �����
					t += 0.1; //�ð��� �帧
					if (matrix[ROWS - y][x] == 4) //��ź�� ��ǥ���� �¾Ҵٸ�(�迭�� ��� ���� ���� ���� 4���)
					{
						score += 100; //������ 100�� �߰�
						break //j�� ���ư��� for�� Ż��
					}
				}

				matrix[ROWS - y][x] = 0; //���� ��ź�� ��ġ �ʱ�ȭ
			}
			if (matrix[ROWS - y][x] == 4) //break�� ���� j�� ���ư��� for���� Ż���ߴٸ�(��ź�� ��ǥ���� �¾Ҵٸ�)
				break //i�� ���ư��� for�� Ż��
		}
		system("cls"); //�� ���� ��ź�� ���ư� �� ȭ�� �����
	}

	print_shell(matrix); //������ ��� Ȯ���� ���� ȭ�� ���(print_shell�Լ� ȣ��)

	return 0;
}

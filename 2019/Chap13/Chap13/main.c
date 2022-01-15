//������Ű��а� 21912150 ���ϸ�
/*
* Project: Chap13
* Date: 2019.12.04.
* Content: ��� ��ȣ�� ������ ����ϴ� ��й�ȣ ��� ���� ���α׷��� �ۼ��Ͻÿ�..
* - �� ���� ��� ����:
* 1. ��й�ȣ ���� ���
* 2. ���� ���
* - ��й�ȣ ���� ��忡���� ������ ��й�ȣ�� �ƴ� ����� ���ؼ� ���ο� ��й�ȣ���� ������ ���
* - �ʱ� ��й�ȣ: "1234"
* - ���� ��忡���� ���� ��й�ȣ ������� ���� ����
* - ���� ��忡���� ��й�ȣ�� ������ ���� ����
* - ���� ��忡�� ��й�ȣ�� �߸��� ���, Ʋ�� ������ ������ ���
*/
#include <stdio.h>
#include <string.h>

int change_password(char* password)	//number�� 1�̸� password�� �ٲ��ִ� �Լ�
{
	char f_password[50];
	char new_password[50];
	int i;
	int result = 0;

	printf("Enter the current password:");	//������ ��й�ȣ�� Ȯ���ϱ� ���� ���ڿ� �Է�
	scanf("%s", f_password);

	if (strcmp(password, f_password) == 0)	//Ȯ���ϱ� ���� ���ڿ��� password�� ���ٸ�
	{
		printf("Enter the new password:");	//�� ��й�ȣ �Է�
		scanf("%s", new_password);

		strcpy(password, new_password);	//������ ��й�ȣ �迭�� �� ��й�ȣ ����, �ٿ��ֱ�
		printf("Password updated: %s\n\n", password);

		result = 1;	//main�� do-while���� �ݺ������ֱ� ���� ���
	}

	else	//Ȯ���ϱ� ���� ���ڿ��� password�� ���� �ʴٸ�
	{
		printf("Your password is incorrect!\n\n");
		result = 1; // main�� do-while���� �ݺ������ֱ� ���� ���
	}

	return result;	//����� ��ȯ
}

int authentication(char* password)	//�Լ� �ȿ��� �Է¹��� ��й�ȣ�� ������ ��й�ȣ�� ������ �Ǵ��ϱ� ���� �Լ�
{
	char f_password[50];
	int count = 0;
	int result = 0;
	int i;

	printf("Enter the password:");	//��й�ȣ �Է¹ޱ�
	scanf("%s", f_password);

	if (strcmp(password, f_password) == 0)	//������ ��й�ȣ�� �Է¹��� ��й�ȣ�� ���ٸ�
	{
		printf("Your password is correct!\n");
		printf("You can access the system.");
	}

	else	//������ ��й�ȣ�� �Է¹��� ��й�ȣ�� �ٸ��ٸ�
	{
		for (i = 0; i < strlen(password) || i < strlen(f_password); i++)
		{
			if (password[i] != f_password[i])	//�ܾ� �ϳ��� ������ �� password�� f_password�� �ٸ���
				count++;	//�ٸ� ���ڿ��� ���� ����
		}

		printf("Your password is incorrect!\n");
		printf("Password is different by %d characters.\n\n", count);

		result = 1;	//main�� do-while���� �ݺ������ֱ� ���� ���
	}

	return result;	//����� ��ȯ
}

int main(void)
{
	int number = 0;
	int result = 0;
	char password[50] = "1234";

	do
	{
		printf("1: change password\n");
		printf("2: authentication\n");
		printf("Mode selection:");
		scanf("%d", &number);

		if (number == 1)	//number�� 1�̸� ��й�ȣ �ٲٴ� �Լ� ȣ��
			result = change_password(password);

		else	//number�� 1�� �ƴϸ� ��й�ȣ Ȯ�� �Լ� ȣ��
			result = authentication(password);
	} while (result != 0);	//��ȯ�� ���� 0�� �ƴϸ� ��� �ݺ�

	return 0;
}
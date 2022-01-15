//정보통신공학과 21912150 김하림
/*
* Project: Chap13
* Date: 2019.12.04.
* Content: 비밀 번호의 변경을 허용하는 비밀번호 기반 인증 프로그램을 작성하시오..
* - 두 가지 모드 지원:
* 1. 비밀번호 변경 모드
* 2. 인증 모드
* - 비밀번호 변경 모드에서는 기존의 비밀번호를 아는 사람에 대해서 새로운 비밀번호로의 변경을 허용
* - 초기 비밀번호: "1234"
* - 인증 모드에서는 현재 비밀번호 기반으로 인증 수행
* - 인증 모드에서는 비밀번호가 맞으면 수행 종료
* - 인증 모드에서 비밀번호가 잘못된 경우, 틀린 문자의 개수를 출력
*/
#include <stdio.h>
#include <string.h>

int change_password(char* password)	//number가 1이면 password를 바꿔주는 함수
{
	char f_password[50];
	char new_password[50];
	int i;
	int result = 0;

	printf("Enter the current password:");	//현재의 비밀번호를 확인하기 위한 문자열 입력
	scanf("%s", f_password);

	if (strcmp(password, f_password) == 0)	//확인하기 위한 문자열이 password와 같다면
	{
		printf("Enter the new password:");	//새 비밀번호 입력
		scanf("%s", new_password);

		strcpy(password, new_password);	//기존의 비밀번호 배열에 새 비밀번호 복사, 붙여넣기
		printf("Password updated: %s\n\n", password);

		result = 1;	//main의 do-while문을 반복시켜주기 위한 결과
	}

	else	//확인하기 위한 문자열이 password와 같지 않다면
	{
		printf("Your password is incorrect!\n\n");
		result = 1; // main의 do-while문을 반복시켜주기 위한 결과
	}

	return result;	//결과값 반환
}

int authentication(char* password)	//함수 안에서 입력받은 비밀번호와 기존의 비밀번호가 같은지 판단하기 위한 함수
{
	char f_password[50];
	int count = 0;
	int result = 0;
	int i;

	printf("Enter the password:");	//비밀번호 입력받기
	scanf("%s", f_password);

	if (strcmp(password, f_password) == 0)	//기존의 비밀번호와 입력받은 비밀번호가 같다면
	{
		printf("Your password is correct!\n");
		printf("You can access the system.");
	}

	else	//기존의 비밀번호와 입력받은 비밀번호가 다르다면
	{
		for (i = 0; i < strlen(password) || i < strlen(f_password); i++)
		{
			if (password[i] != f_password[i])	//단어 하나씩 비교했을 때 password와 f_password가 다르면
				count++;	//다른 문자열의 개수 세기
		}

		printf("Your password is incorrect!\n");
		printf("Password is different by %d characters.\n\n", count);

		result = 1;	//main의 do-while문을 반복시켜주기 위한 결과
	}

	return result;	//결과값 반환
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

		if (number == 1)	//number가 1이면 비밀번호 바꾸는 함수 호출
			result = change_password(password);

		else	//number가 1이 아니면 비밀번호 확인 함수 호출
			result = authentication(password);
	} while (result != 0);	//반환된 값이 0이 아니면 계속 반복

	return 0;
}
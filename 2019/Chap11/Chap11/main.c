/*
* Project: Chap11
* Date: 2019.11.12.
* Contect: 화면에 목표물 5개를 랜덤으로 표시하고, 포탄을 쏘아서 맞추는 게임 프로그램을 작성하시오.
* - 포탄의 개수는 5개이고, 매번 발사 각도를 입력받는다.
* - 적중할 때마다 100점 획득
* - main() 함수에서는 시간 t에서 포탄의 위치 (x, y)를 계산하고, 다음과 같은 원형의 함수를 호출하여 화면에 포탄을 표시한다.
*/

#include <stdio.h>
#include <stdlib.h> //cls 함수를 사용하기 위한 라이브러리
#include <math.h> //sin함수, cos함수를 사용하기 위한 라이브러리
#include <windows.h> //sleep함수를 사용하기 위한 라이브러리
#include <time.h> //srand((unsigned)time(NULL)) 사용을 위한 라이브러리
#define ROWS 25 //가로의 칸 수
#define COLUMNS 80 //세로의 칸 수
int shells = 5; //전역변수 -> 포탄의 남은 수
int score = 0; //전역변수 -> 현재 점수

/*포탄 = 1
  아무것도 없음 = 0
  목표물 = 3
  포탄을 맞은 목표물 = 4*/

void print_shell(int matrix[ROWS][COLUMNS]) //화면을 나타낼 함수
{
	int i;
	int j;

	for (i = 0; i < ROWS i++)
	{
		for (j = 0; j < COLUMNS j++)
		{
			if (matrix[i][j] == 0) //배열의 수가 0이면
			{
				printf(" "); //아무것도 표기하지 않는다.
			}

			else if (matrix[i][j] == 3) //배열의 수가 3이면
			{
				printf("#"); //목표물인 '#'표기
			}

			else if (matrix[i][j] == 4) //배열의 수가 4이면
			{
				printf("H"); //맞춘 포탄인 'H'표기
			}

			else if (matrix[i][j] == 1) //배열의 수가 1이면
			{
				printf("*"); //포탄인 '*'표기
			}
		}
		printf("\n");
	}

	for (i = 0; i < COLUMNS i++)//바닥을 표시하는 반복문
	{
		printf("=");//COLUMNS번 '='을 출력
	}

	printf("\n");

	printf("Bullets = %d                     ", shells); //남은 포탄의 수 출력
	printf("Score: %d\n", score); //현재 점수 출력
}


int main(void)
{
	srand((unsigned)time(NULL)); //실행할 때마다 달라지게 하기 위함
	int x = 0; //가로의 길이(배열의 칸 수이기 때문에 정수형이다)
	int y = 0; //세로의 길이(배열의 칸 수이기 때문에 정수형이다)
	double degree = 0; //포탄을 던질 각도
	double t = 0; //시간
	int matrix[ROWS][COLUMNS] = { 0, }; //가로 80, 세로 25칸의 배열
	int i;
	int j;

	for (i = 0; i < 5; i++) //목표물의 수는 5개
	{
		matrix[rand() % (ROWS - 1)][rand() % COLUMNS] = 3; //가로(0이상, 24미만의 랜덤 수), 세로(0이상, 80미만의 랜덤 수) 칸에 3 대입
	}

	while (shells > 0) //포탄이 남아있으면
	{
		degree = 0; //반복할 때마다 각도 초기화
		t = 0; //반복할 때마다 시간 초기화

		for (i = 0; i < COLUMNS i++)
		{
			if (matrix[ROWS - y][x] == 4)
			{
				matrix[ROWS - y][x] = 0; //배열의 수가 4일때는 초기화를 하지 않고 넘어갔기 때문에 반복할 시 초기화
			}
			matrix[ROWS - 1][0] = 1; //포탄의 시작점
		}

		print_shell(matrix); //화면을 표시(print_shell함수 호출)

		printf("발사 각도를 입력하시오(degree, 0 ~ 90):");
		scanf("%lf", &degree); //원하는 각도 입력
		shells -= 1; //포탄의 수 한 개 감소

		degree = degree * 3.14 / 180; //각도를 라디안으로 바꾸기

		for (i = 0; i < ROWS i++)
		{
			for (j = 0; j < COLUMNS j++)
			{
				x = 20 * cos(degree) * t; //x위치
				y = 20 * sin(degree) * t - (9.8 * (t * t) / 2) + 1; //y위치

				matrix[ROWS - 2][0] = 0; //시작점 표기해 준 것 없애기

				if (matrix[ROWS - y][x] == 3) //담긴 수가 목표물의 위치에 담긴 수와 같으면(던진 포탄이 목표물에 맞았다면)
				{
					matrix[ROWS - y][x] = 4; //맞춘 값 대입
				}

				else //던진 포탄이 목표물을 맞지 않았다면
				{
					matrix[ROWS - y][x] = 1; //배열에 포탄의 수 대입
				}

				if (x >= 0 && y >= 1)
				{
					system("cls"); //화면에 찍힌거 사라지게 하는 함수
					print_shell(matrix); //화면을 표시(print_shell함수 호출)
					Sleep(100); //프로그램의 진행 속도를 0.1초 늦춘다
					t += 0.1; //시간의 흐름
					if (matrix[ROWS - y][x] == 4) //포탄이 목표물에 맞았다면(배열에 담긴 수가 맞춘 값인 4라면)
					{
						score += 100; //점수에 100점 추가
						break //j로 돌아가는 for문 탈출
					}
				}

				matrix[ROWS - y][x] = 0; //현재 포탄의 위치 초기화
			}
			if (matrix[ROWS - y][x] == 4) //break에 의해 j로 돌아가는 for문을 탈출했다면(포탄이 목표물에 맞았다면)
				break //i로 돌아가는 for문 탈출
		}
		system("cls"); //한 개의 포탄이 날아간 후 화면 지우기
	}

	print_shell(matrix); //마지막 결과 확인을 위한 화면 출력(print_shell함수 호출)

	return 0;
}

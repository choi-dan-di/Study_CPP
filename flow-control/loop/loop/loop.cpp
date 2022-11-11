#include <iostream>
using namespace std;

int main()
{
#pragma region while문
	int count = 0;

	while (count < 5)
	{
		cout << "while : Hello World" << endl;
		count++;
	}

	/*
	// do ~ while문
	do
	{
		cout << "hello world" << endl;
		count++;
	} while (false);
	*/
#pragma endregion

#pragma region for문
	for (int i = 0; i < 5; i++)
	{
		cout << "FOR : Hello World" << endl;
	}
#pragma endregion

#pragma region break 개념 이해하기
	int round = 1;
	int hp = 100;
	int damage = 10;

	// 무한 루프 : 전투 시작
	while (true)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;	// 음수 체력을 0으로 보정

		// 시스템 메시지
		cout << "Round : " << round << ", 몬스터 체력 : " << hp << endl;

		// 나갈 수 있는 조건 판별 위해
		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			// if문이 아닌 while문을 빠져나가라는 의미
			break;
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}
#pragma endregion

#pragma region continue 개념 이해하기
	// 1부터 10 사이의 홀수만 출력하기
	// 1, 3, 5, 7, 9
	for (int i = 1; i <= 10; i++)
	{
		// 짝수 판단
		bool isEven = ((i % 2) == 0);

		if (isEven)
			// 아래 코드 skip
			continue;

		cout << i << endl;
	}
#pragma endregion
}
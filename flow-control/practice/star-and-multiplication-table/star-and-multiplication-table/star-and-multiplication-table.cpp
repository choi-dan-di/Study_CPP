#include <iostream>
using namespace std;

int main()
{
#pragma region 별찍기
	// 별찍기
	int input;
	cout << "정수를 입력해주세요. : ";
	cin >> input;

	// 유저들이 어떤 정수(n)를 입력하면 n*n개의 별을 찍어서 출력하기
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "-----------------------" << endl;

	// 1개부터 시작해서 순차적으로 줄마다 증가하는 별 출력하기
	for (int i = 1; i <= input; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "-----------------------" << endl;

	// n개부터 시작해서 줄마다 1개씩 줄어드는 형태로 별 출력하기
	for (int i = input; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "-----------------------" << endl;

	// 다른 버전
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < (input - i); j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "-----------------------" << endl;
	cout << "-----------------------" << endl;
	cout << "-----------------------" << endl;
#pragma endregion

#pragma region 구구단
	// 구구단
	// 2단부터 9단까지 출력하기
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << (i * j) << endl;
		}
		cout << endl;
	}
#pragma endregion
}
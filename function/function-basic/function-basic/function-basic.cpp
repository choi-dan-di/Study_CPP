#include <iostream>
using namespace std;

// 함수 기초

// Hello World를 콘솔에 출력하는 함수 만들어보기
// input : 없음 / output : 없음
void PrintHelloWorld()
{
    cout << "Hello World!" << endl;
}

// 정수를 입력받아 콘솔에 출력하는 함수를 만들어보기
// input : int / output : 없음
void PrintNumber(int num)
{
    cout << "넘겨주신 숫자는 " << num << "입니다." << endl;
}

// 2를 곱하고 결과물을 출력하는 함수 만들어보기
// input : int / output : int
int MultiplyBy2(int num)
{
    return num * 2;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보기
// input : int, int / output : int
int MultiplyBy(int a, int b)
{
    return a * b;
}

int main()
{
    PrintHelloWorld();
    PrintNumber(3);

    PrintNumber(MultiplyBy2(3));
    PrintNumber(MultiplyBy(5, 3));
}

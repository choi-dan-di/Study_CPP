#include <iostream>
using namespace std;

// 호출 스택

// 함수 선언
// 매개 변수 이름은 생략 가능하지만 
// 가능한 어떻게 사용되어지는지를 알게 하기위해 정해두는 편이 좋다.
void Func1();
void Func2(int a, int b);
// void Func2(int, int);
void Func3(float a);
// void Func3(float);

int main()
{
    cout << "main" << endl;
    Func1();
}

void Func1()
{
    cout << "Func1" << endl;

    // push 2
    // push 1
    // call Func2
    Func2(1, 2);

    Func3(10.0f);
}

/*
void Func2(int a, int b)
{
    cout << "Func2" << endl;

    Func3(10);
}
*/

void Func3(float a)
{
    cout << "Func3" << endl;
}

#include <iostream>
using namespace std;

// 전역 변수, 지역 변수와 값 전달

// 전역 변수
// 어디에서나 접근이 가능하다.
int globalValue = 0;

void Test()
{
    cout << "전역 변수의 값은 " << globalValue << endl;
    globalValue++;
}

void IncreaseHp(int hp)
{
    hp = hp + 1;
}

int main()
{
    cout << "전역 변수의 값은 " << globalValue << endl;
    globalValue++;

    Test();

    // 지역 변수
    // 함수 내부에서 선언하고 해당 함수에서만 접근이 가능하다.
    int localValue = 1;

    localValue++;

    int hp = 1;

    cout << "Increase 호출 전 : " << hp << endl;
    IncreaseHp(hp);
    cout << "Increase 호출 후 : " << hp << endl;

    return 0;
}
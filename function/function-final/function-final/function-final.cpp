#include <iostream>
using namespace std;

// 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
int Add(int a, int b)
{
    int result = a + b;
    return result;
}

/*
float AddFloat(float a, float b)
{
    float result = a + b;
    return result;
}
*/
// Add 함수 오버로딩
float Add(float a, float b)
{
    float result = a + b;
    return result;
}

int Add(int a)
{
    int result = a + 1;
    return result;
}

// 기본 인자값
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0, int castleId = 2)
{
    cout << "hp : " << hp << endl;
    cout << "mp : " << mp << endl;
    cout << "attack : " << attack << endl;
    cout << "guildId : " << guildId << endl;
    cout << "castleId : " << castleId << endl;
}

// 스택 오버플로우
int Factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * Factorial(n - 1);
}

int main()
{
    float result = Add(1.5f, 2.1f);
    //float resuldt = AddFloat(1.5f, 2.1f);
    cout << result << endl;

    cout << endl;

    SetPlayerInfo(100, 40, 10, 1);

    cout << endl;

    int result2 = Factorial(5);
    //int result2 = Factorial(1000000); // 스택 오버플로우
    cout << result2 << endl;
}
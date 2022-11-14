#include <iostream>
using namespace std;

// 스택 프레임
// 데이터가 어떤 과정으로 스택 프레임이 저장이 되는지 살펴보기

void PrintNumber(int num)
{
    cout << "넘겨주신 숫자는 " << num << "입니다." << endl;
}

int MultiplyBy(int a, int b)
{
    int c = a * b;
    return c;
}

int main()
{
    int a = 3;
    int b = 5;
    int result = MultiplyBy(a, b);

    PrintNumber(result);
}
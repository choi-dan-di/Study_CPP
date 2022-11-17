#include <iostream>
using namespace std;

// 포인터

void SetHp(int* hp)
{
    *hp = 100;
}

int main()
{
    int hp = 1;
    SetHp(&hp);

    // 지금까지 사용한 방식
    // number라는 이름의 4바이트 정수 타입의 바구니를 만든다.
    // number라는 변수는 스택 메모리에 할당된다.
    // number = 1이라 함은 number 바구니에 1이라는 숫자를 넣으라는 의미이다.
    // 따라서 스택 메모리에 있는 특정 주소(number 바구니)에 우리가 원하는 값을 넣은 셈이다.
    // 나쁘지 않고 편리하지만 단점은 원본을 수정하기가 어렵다.
    int number = 1;

    // 포인터는 메모리의 주소를 담는 의미이다.
    // 변수가 값을 담는 게 아닌, 주소를 담게 된다.
    int* ptr = &number;

    cout << number << endl;

    // 추가 문법 : 주소를 저장하는 바구니가 가리키는 주소로 가서 무엇인가를 해라

    // 값을 가져오기
    int value1 = *ptr;
    *ptr = 2;

    cout << number << endl;

    // type은 왜 붙여줄까?
    // 어떤 값인지 알려줘서 분석할 때 참고하라고

    // 타입의 불일치
    // __int64* ptr2 = &number;    // 에러남
    //__int64* ptr2 = (__int64*)&number;

    //*ptr2 = 0xAABBCCDDEEFF;

    return 0;
}
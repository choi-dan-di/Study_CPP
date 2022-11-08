#include <iostream>
using namespace std;

// 데이터를 가공하는 방법에 대해 알아보기

#pragma region 산술 연산 변수
// a[ 1 ]
// a라는 이름의 변수를 할당하고 안에 1을 넣는다
int a = 1;

// b[ 2 ]
// b라는 이름의 변수를 할당하고 안에 2를 넣는다
int b = 2;
#pragma endregion

#pragma region 비교 연산 변수
bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;
#pragma endregion

#pragma region 논리 연산 변수
bool test;

int hp = 100;
bool isInvincible = true;   // 무적 여부
#pragma endregion

#pragma region 비트 연산 변수
// 실습 부분에 사용되는 변수
unsigned char flag;     // 부호를 없애야 >>(우측 시프트)를 하더라도 부호비트가 딸려오지 않는다.
#pragma endregion

int main()
{
#pragma region 산술 연산
    // 산술 연산자는 대입 연산과 사칙 연산이 있다.

    // 대입 연산
    // a에 b를 대입하고 b를 반환하라
    a = b;

    // 사칙 연산
    a = b + 3;  // 덧셈 add
    a = b - 3;  // 뺄셈 sub
    a = b * 3;  // 곱셈 mul
    a = b / 3;  // 나눗셈 div
    a = b % 3;  // 나머지 div

    a += 3;     // a = a + 3;
    a -= 3;
    a *= 3;
    a /= 3;
    a %= 3;

    // 증감 연산자
    a = a + 1;  // add eax, 1 -> inc eax
    a++;
    ++a;
    a--;
    --a;

    b = a++;    // b = a 먼저 실행된 후 a를 1 증가
    b = ++a;    // a를 1 증가시킨 후 b = a
#pragma endregion

#pragma region 비교 연산
    // 서로 다른 두 값을 비교할 때 사용
    // 
    // a == b : 같으면 1, 다르면 0
    isSame = (a == b);
    
    // a != b : 다르면 1, 같으면 0
    isDifferent = (a != b);

    // a > b, a >= b, a < b, a <= b : 참이면 1, 거짓이면 0
    isGreater = (a > b);
    isSmaller = (a < b);
#pragma endregion

#pragma region 논리 연산
    // ! : not. 0이면 1, 그 외는 0
    test = !isSame; // 사실상 isDifferent의 의미

    // && : and. 두 조건 모두 1이면 1, 그 외는 0
    test = (hp <= 0 && isInvincible == false);    // 죽음

    // || : or. 두 조건 중에 하나만 1이면 1, 모두 0이면 0
    test = (hp > 0 || isInvincible == true);      // 생존
    // test = !(hp <= 0 && isInvincible == false);  // 위와 같은 의미
#pragma endregion

#pragma region 비트 연산
    // ~ : bitwise not
    // 단일 숫자의 모든 비트를 대상으로 0과 1을 서로 뒤바꾼다.

    // & : bitwise and
    // 두 숫자의 모든 비트 쌍을 대상으로 AND 연산을 한다.

    // | : bitwise or
    // 두 숫자의 모든 비트 쌍을 대상으로 OR 연산을 한다.

    // ^ : bitwise xor
    // 두 숫자의 모든 비트 쌍을 대상으로 XOR 연산을 한다.
    // 다르면 1, 같으면 0을 반환한다.
    int xa = 1;
    int xb = 123;

    xa = xa ^ xb;   // 결과값 : 122
    // cout << xa << endl;
    xa = xa ^ xb;   // 결과값 : 1 (원래 xa의 값)

    cout << xa << endl;

    // << : 왼쪽 시프트(비트 좌측 이동)
    // 비트열을 n만큼 왼쪽으로 이동
    // 왼쪽에 넘치는 n개의 비트는 사라지고 오른쪽에 새로 생기는 n개의 비트는 0으로 채워진다.
    // *2를 할 때 자주 보이는 패턴 (이진수라서)

    // >> : 오른쪽 시프트(비트 우측 이동)
    // 비트열을 n만큼 오른쪽으로 이동
    // 왼쪽에 새로 생기는 n개의 비트는 0으로 채워지고 오른쪽에 넘치는 n개의 비트는 사라진다.
    // ⭐ 단, 부호 비트가 존재할 경우(음수일 경우), 부호 비트는 유지된다.

    // 실습
    // 0b0000 [무적][변이][스턴][공중부양]

    // 무적 상태로 만든다
    /* 
        // flag = 8;
        위 처럼 비트에 해당하는 값을 직접 입력해도 되지만, 
        4비트가 아닌 64비트라고 생각했을 땐 수가 굉장히 커지게 된다.
        그래서 아래처럼 조립해서 넣는 게 좋다.
    */
    flag = (1 << 3);    // 지금은 3으로 하드코딩 했지만, 나중엔 무적이라는 값을 3으로 세팅하는 방식을 사용한다.

    // 변이 상태를 추가한다 (무적 + 변이)
    // 1이 하나라도 있으면 1이 반환되는 bitwise or 연산을 사용한다.
    flag |= (1 << 2);

    // 무적인지 확인하고 싶으면? (다른 상태는 관심 없음)
    // 이럴 때 bitmask를 사용한다.
    // bitmask : 해당 위치만 1로 둔 값. 여기선 (1 << 3)
    // 현재 상태값(flag)과 bitmask를 bitwise and 연산하면 원하는 상태값을 얻을 수 있다.
    bool invincible = ((flag & (1 << 3)) != 0);

    // 무적이거나 스턴 상태인지 확인하고 싶다면?
    // bitmask = 0b1010
    // bool stunOrInvincible = ((flag & 0b1010) != 0);
    int mask = (1 << 3) | (1 << 1);
    bool stunOrInvincible = ((flag & mask) != 0);
#pragma endregion
}





#include <iostream>
using namespace std;

// 함수 포인터2 : 멤버 함수 포인터

// typedef의 진실
// typedef 왼쪽 오른쪽 -> 오른쪽 (커스텀 타입 정의)
typedef int NUMBER;
// 더욱 복잡해지면 규칙을 지키기 힘들다.
// 정확히는 왼쪽/오른쪽 기준이 아니라,
// [선언 문법]에서 typedef를 앞에다 붙이는 쪽 기준이라고 볼 수 있다.
typedef int INTEGER;
typedef int* POINTER;
// typedef int FUNC(int, int);  // 아래 방법을 더 선호.
typedef int ARRAY[20];

// 선언부(함수 내부)에서 FUNC t;를 쓸 일은 거의 없다. 전방 선언과 비슷한 의미
// 고로 typedef 할 때 포인터까지 한데 묶어 적어두면 편리하다.
typedef int(*PFUNC)(int, int);

int Test(int a, int b)
{
    cout << "Test" << endl;
    return a + b;
}

class Knight
{
public:
    // 정적 함수
    static void HelloKnight()
    {
        cout << "HelloKnight()" << endl;
    }

    // 멤버 함수
    int GetHp()
    {
        cout << "GetHp()" << endl;
        return _hp;
    }
public:
    int _hp = 100;
};

int main()
{
    int(*fn)(int, int);

    // FUNC* fn2;
    PFUNC fn2;

    // typedef int(FUNC_TYPE)(int, int);
    // FUNC_TYPE* fn;

    ARRAY a;    // int 타입의 크기 20짜리 배열 생성

    fn = &Test; // & 생략 가능 (C언어와의 호환성 때문. 가독성 측면에서 웬만하면 붙이는 게 좋다.)

    fn(1, 2);

    (*fn)(1, 2);

    // 위 문법으로 만든 함수 포인터는 [전역 함수 / 정적 함수]만 담을 수 있다. (호출 규약이 동일한 애들)
    // 멤버 함수는 담을 수 없다.
    // fn = &Knight::GetHp; // 불가능
    // int(*fn4)() = &Knight::GetHp;    // 불가능
    // void(*fn3)() = &Knight::HelloKnight; // 가능

    // 멤버 함수에 대한 포인터 타입 만들어보기
    typedef int(Knight::*PMEMFUNC)();
    PMEMFUNC mfn;
    mfn = &Knight::GetHp;   // 멤버 함수 포인터에는 &를 반드시 붙여줘야한다.

    Knight k1;
    // k1.GetHp();
    // 혹여나 같은 이름의 변수나 함수가 존재하면 중복이 되기 때문에 그러한 문제를 방지하기 위해 *을 붙인다.
    // -> 함수라는 것을 알려줌
    (k1.*mfn)();

    Knight* k2 = new Knight();
    // 같은 의미
    ((*k2).*mfn)();
    (k2->*mfn)();
    delete k2;

    int(Knight::*mfn2)() = &Knight::GetHp;
    (k1.*mfn2)();

    return 0;
}
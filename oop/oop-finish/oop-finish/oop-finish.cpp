#include <iostream>
using namespace std;

// 객체지향 마무리

// [1] C++에서 struct와 class는 종이 한 장 차이이다.
// struct는 기본 접근 지정자가 public이고, class는 private이다.
// 왜 나뉘어졌을까?
// - C++은 C언어에서 파생되어 발전했기 때문에 호환성을 지키기 위함
// -> struct는 그냥 구조체(데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

struct TestStruct
{
    int _a;
    int _b;
};

class TestClass
{
    int _a;
    int _b;
};

// [2] static 변수, static 함수 (static = 정적 = 고정된)
class Marine
{
public:
    void TakeDamage(int damage)
    {
        _hp -= damage;
    }

    static void SetAttack()
    {
        // _hp = 100;   // 안 됨
        s_attack = 10;

    }

public:
    // 특정 마린 객체에 종속적
    int _hp;

    // 특정 마린 객체와 무관
    // 마린이라는 클래스 자체와 연관
    static int s_attack; // 설계도상으로만 존재
};

// static 변수는 어떤 메모리에 올라갈까?
// 초기화 하면 .data
// 초기화 안 하면 .bss
int Marine::s_attack = 0;

class Player
{
public:
    int _id;
};

// 정적 전역 객체
static int s_id = 1;

int GenerateId()
{
    // 생명주기 : 프로그램 시작/종료(메모리에 항상 올라가 있음)
    // 가시범위 : 함수 내부

    // 정적 지역 객체
    static int s_id = 1;
    return s_id++;
}

int main()
{
    // [1]
    TestStruct ts;
    ts._a;

    TestClass tc;
    //tc._a;  // 기본적으로 접근 지정자를 설정하지 않으면 private

    // [2]
    Marine m1;
    m1._hp = 40;
    //m1.s_attack = 6;

    Marine m2;
    m2._hp = 40;
    //m2.s_attack = 6;

    Marine::s_attack = 6;

    // 마린 공격력 업그레이드 완료 ! (Academy에서 업그레이드 끝)
    //m1.s_attack = 7;
    //m2.s_attack = 7;
    Marine::s_attack = 7;

    Marine::SetAttack();

    // 스택 아님. .data 영역
    static int id = 10;
    int a = id;

    cout << GenerateId() << endl;
    cout << GenerateId() << endl;
    cout << GenerateId() << endl;
    cout << GenerateId() << endl;
    cout << GenerateId() << endl;

    return 0;
}
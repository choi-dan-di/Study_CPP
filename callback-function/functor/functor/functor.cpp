#include <iostream>
using namespace std;

// 함수 객체 (Functor)
// -> 함수처럼 동작하는 객체이다.

void HelloWorld()
{
    cout << "Hello World" << endl;
}

void HelloNumber(int number)
{
    cout << "Hello Number : " << number << endl;
}

class Knight
{
public:
    void AddHp(int addHp)
    {
        _hp += addHp;
    }
private:
    int _hp = 100;
};

class Functor
{
public:
    void operator()()
    {
        cout << "Functor Test" << endl;
        cout << _value << endl;
    }

    bool operator()(int num)
    {
        cout << "Functor(int) Test" << endl;
        _value += num;
        cout << _value << endl;

        return true;
    }
private:
    int _value = 0;
};

class MoveTask
{
public:
    void operator()()
    {
        // TODO
        cout << "해당 좌표로 플레이어 이동" << endl;
    }
public:
    int _playerId;
    int _posX;
    int _posY;
};

int main()
{
    // 함수 포인터 선언
    void (*pfunc)(void);
    // 동작을 넘겨줄 때 유용하다.
    pfunc = &HelloWorld;
    (*pfunc)();

    // 함수 포인터의 단점
    // 1) 시그니처가 안 맞으면 사용할 수 없다.
    // 2) 상태를 가질 수 없다.
    // -> 상태란 각 클래스, 함수 내의 컨디션을 의미한다. (ex. 멤버 변수, 멤버 함수 등)
    // pfunc = &HelloNumber;

    // [함수처럼 동작]하는 객체
    // () 연산자 오버로딩이 필요하다.
    HelloWorld();

    Functor functor;
    functor();
    bool ret = functor(3);

    // MMO에서 함수 객체를 사용하는 예시
    // 클라 <-> 서버
    // 서버 : 클라사 보내준 네트워크 패킷을 받아서 처리
    // ex) 클라 : 나 (5, 0) 좌표로 이동시켜줘!
    MoveTask task;

    // 함수 포인터와 비교해 생성 시점과 실행 시점을 분리할 수 있는 것이 장점이다.
    // 기다렸다가 나중에 여유 될 때 일감을 실행할 수 있다.
    task();

    return 0;
}
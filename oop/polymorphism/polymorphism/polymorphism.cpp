﻿#include <iostream>
using namespace std;

// 다형성

// 객체 지향 프로그래밍(OOP : Object Oriented Programming)
// - 상속성
// - 은닉성 
// - 다형성 (V)

// 다형성(Polymorphism = Poly + morph) : 겉은 똑같은데 기능이 다르게 동작한다.
// - 오버로딩(Overloading) = 함수 중복 정의 = 함수 이름의 재사용
// - 오바라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding) = 묶는다
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynamic Binding) : 실행 시점에 결정

// 일반 함수는 정적 바인딩을 기본으로 사용
// 동적 바인딩을 원한다면? -> 가상 함수(Virtual Function)를 사용해야한다.

// 그런데 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상 함수를 호출해준걸까?
// - 가상 함수 테이블(vftable)

// .vftable [] 4바이트(32) 8바이트(64)

// [VMove] [VDie]

// 순수 가상 함수 : 구현은 없고 '인터페이스'만 전달하는 용도로 사용하고 싶을 경우
// 추상 클래스 : 순수 가상 함수가 1개 이상 포함되면 바로 추상 클래스로 간주
// - 직접적으로 객체를 만들 수 없게 됨

class Player
{
public:
    Player()
    {
        _hp = 100;
    }

    void Move() { cout << "Move Player !" << endl; }
    // void Move(int a) { cout << "Move Player (int) !" << endl; }
    virtual void VMove() { cout << "VMove Player !" << endl; }
    virtual void VDie() { cout << "VDie Player !" << endl; }

    // 순수 가상 함수
    virtual void VAttack() = 0;
public:
    int _hp;
};

class Knight : public Player
{
public:
    Knight()
    {
        _stamina = 100;
    }

    void Move() { cout << "Move Knight !" << endl; }
    // 가상 함수는 재정의를 하더라도 가상 함수이다.
    virtual void VMove() { cout << "VMove Knight !" << endl; }
    virtual void VDie() { cout << "VDie Knight !" << endl; }

    virtual void VAttack() { cout << "VAttack Knight !" << endl; }
public:
    int _stamina;
};

class Mage : public Player
{
public:
public:
    int _mp;
};

void MovePlayer(Player* player)
{
    player->VMove();
    player->VDie();
}

void MoveKnight(Knight* knight)
{
    // knight->Move();
    knight->Move();
}

int main()
{
    // Player p;    // 순수 가상 함수로 인해 선언 불가
    // MovePlayer(&p); // 플레이어는 플레이어다? YES
    // MoveKnight(&p);  // 플레이어는 기사다? NO

    Knight k;
    // MoveKnight(&k); // 기사는 기사다? YES
    MovePlayer(&k); // 기사는 플레이어다? YES

    return 0;
}
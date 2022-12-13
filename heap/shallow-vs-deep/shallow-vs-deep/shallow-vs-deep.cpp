﻿#include <iostream>
using namespace std;

// 얕은 복사 vs 깊은 복사

class Pet
{
public:
    Pet()
    {
        cout << "Pet()" << endl;
    }
    
    ~Pet()
    {
        cout << "~Pet()" << endl;
    }

    Pet(const Pet& pet)
    {
        cout << "Pet(const Pet& pet)" << endl;
    }

    Pet& operator=(const Pet& pet)
    {
        cout << "operator=(const Pet& pet)" << endl;
        return *this;
    }
};

class RabbitPet : public Pet
{

};

class Player
{
public:
    Player()
    {
        cout << "Player()" << endl;
    }

    // 복사 생성자
    Player(const Player& player)
    {
        cout << "Player(const Player& player)" << endl;
        _level = player._level;
    }

    // 복사 대입 연산자
    Player& operator=(const Player& player)
    {
        cout << "operator=(const Player&)" << endl;
        _level = player._level;
        return *this;
    }
public:
    int _level = 0;
};

class Knight : public Player
{
public:
    Knight()
    {
        // _pet = new Pet();
    }

    // 복사 생성자
    Knight(const Knight& knight) : Player(knight), _pet(knight._pet)
    {
        cout << "Knight(const Knight& knight)" << endl;
        _hp = knight._hp;
        // _pet = new Pet(*(knight._pet)); // 깊은 복사
    }

    // 복사 대입 연산자
    Knight& operator=(const Knight& knight)
    {
        cout << "operator=(const Knight& knight)" << endl;

        Player::operator=(knight);
        _pet = knight._pet;

        _hp = knight._hp;
        //_pet = new Pet(*(knight._pet)); // 깊은 복사
        return *this;
    }

    ~Knight()
    {
        //delete _pet;
    }
public:
    int _hp = 100;
    Pet _pet;
    //Pet* _pet;
};

int main()
{
    // Pet* pet = new Pet();

    Knight knight;  // 기본 생성자
    knight._hp = 200;
    // knight._pet = pet;
    knight._level = 99;

    cout << "-------------- 복사 생성자 --------------" << endl;
    Knight knight2 = knight;    // 복사 생성자
    // Knight knight3(knight);  // 같은 의미

    Knight knight3; // 기본 생성자
    cout << "-------------- 복사 대입 연산자 --------------" << endl;
    knight3 = knight;   // 복사 대입 연산자 (오버로딩)

    // [복사 생성자] + [복사 대입 연산자]
    // 둘 다 안 만들어주면 컴파일러가 '암시적으로' 만들어준다.

    // 중간 결론) 컴파일러가 알아서 잘 만들어준다?라는 의미는
    // 수고하세요~ 다음 주제로 넘어갈까요?라고 생각할 수도 있지만 아니다.
    // 컴파일러가 만들어준 것들로만 사용할 수 없음.

    // [ 얕은 복사 Shallow Copy ]
    // 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)
    // 포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일한 객체를 가리키는 상태가 됨
    // Stack : Knight [ hp 0x1000 ]     -> Heap 0x1000 Pet[    ]
    // Stack : Knight2 [ hp 0x1000 ]    
    // Stack : Knight3 [ hp 0x1000 ]    

    // [ 깊은 복사 Deep Copy ]
    // 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다. (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
    // 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 됨
    // Stack : Knight [ hp 0x1000 ]     -> Heap 0x1000 Pet[    ]
    // Stack : Knight2 [ hp 0x2000 ]    -> Heap 0x2000 Pet[    ]
    // Stack : Knight3 [ hp 0x3000 ]    -> Heap 0x3000 Pet[    ]

    // 실험)
    // - 암시적 복사 생성자 Steps
    // 1) 부모 클래스의 복사 생성자 호출
    // 2) 멤버 클래스의 복사 생성자 호출
    // 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사 Shallow Copy)
    
    // - 명시적 복사 생성자 Steps
    // 1) 부모 클래스의 기본 생성자 호출
    // 2) 멤버 클래스의 기본 생성자 호출

    // - 암시적 복사 대입 연산자 Steps
    // 1) 부모 클래스의 복사 대입 연산자 호출
    // 2) 멤버 클래스의 복사 대입 연산자 호출
    // 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사 Shallow Copy)
    
    // - 명시적 복사 대입 연산자 Steps
    // 1) 알아서 해주는거 없음

    // 왜 이렇게 혼란스러울까?
    // 객체를 '복사' 한다는 것은 두 객체의 값들을 일치시키려는 것
    // 따라서 기본적으로 얕은 복사 (Shallow Copy) 방식으로 동작

    // 명시적 복사 -> [모든 책임]을 프로그래머한테 위임하겠다는 의미

    return 0;
}
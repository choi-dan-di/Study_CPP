#include <iostream>
using namespace std;

// 상속성

// 객체 지향 프로그래밍(OOP : Object Oriented Programming)
// - 상속성 (V)
// - 은닉성
// - 다형성

// 상속(Inheritance) ? 부모 -> 자식에게 유산을 물려주는 것
class Player
{
public:
    Player()
    {
        _hp = 0;
        _attack = 0;
        _defence = 0;
        cout << "Player() 기본 생성자 호출" << endl;
    }

    Player(int hp)
    {
        _hp = hp;
        _attack = 0;
        _defence = 0;
        cout << "Player(int hp) 생성자 호출" << endl;
    }

    ~Player()
    {
        cout << "~Player() 소멸자 호출" << endl;
    }

    void Move() { cout << "Player Move 호출" << endl; }
    void Attack() { cout << "Player Attack 호출" << endl; }
    void Die() { cout << "Player Die 호출" << endl; }

public:
    int _hp;
    int _attack;
    int _defence;
};

// 클래스는 일종의 설계도
class Knight : public Player
{
public:
    Knight()
    {
        _stamina = 100;
        cout << "Knight() 기본 생성자 호출" << endl;
    }

    Knight(int stamina) : Player(100)
    {
        _stamina = stamina;
        cout << "Knight(int stamina) 생성자 호출" << endl;
    }

    ~Knight()
    {
        cout << "~Knight() 소멸자 호출" << endl;
    }
    // 재정의
    void Move() { cout << "Knight Move 호출" << endl; }
public:
    int _stamina;
};

class Mage : public Player
{
public:
public:
    int _mp;
};
/*
class Knight
{
public:
    void Move() {}
    void Attack() {}
    void Die() {}

public:
    int _hp;
    int _attack;
    int _defence;
};

class Mage
{
public:
    void Move() {}
    void Attack() {}
    void Die() {}

public:
    int _hp;
    int _attack;
    int _defence;
};
*/

int main()
{
    Knight k;
    k._hp = 100;
    k._attack = 10;
    k._defence = 5;
    k._stamina = 50;

    Knight k2(100);

    // 재정의 한 Move 호출
    //k.Move();
    // 상속받은 Move 호출
    //k.Player::Move();

    //k.Attack();
    //k.Die();

    return 0;
}
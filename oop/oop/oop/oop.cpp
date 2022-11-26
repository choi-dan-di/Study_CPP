#include <iostream>
using namespace std;

// 객체 지향 프로그래밍

// 데이터 + 가공(로직, 동작)
// 객체 지향은 객체 위주로 진행되는 프로그래밍 방식
// 객체란? 플레이어, 몬스터, GameRoom

// Knight를 설계해보자
// - 속성(데이터) : hp, attack, y, x
// - 기능(동작) : Move, Attack, Die

class Knight
{
public:
    // 멤버 함수 선언
    void Move(int y, int x);
    void Attack();
    // 클래스 내에서 바로 구현 가능
    void Die()
    {
        hp = 0;
        cout << "Die" << endl;
    }
public:
    // 멤버 변수
    int hp;
    int attack;
    int posY;
    int posX;
};

// 멤버 함수 구현
void Knight::Move(int y, int x)
{
    posY = y;
    posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack : " << attack << endl;
}

// Instantiate : 객체를 만든다는 의미
int main()
{
    Knight k1;
    k1.hp = 100;
    k1.attack = 10;
    k1.posY = 0;
    k1.posX = 0;

    Knight k2;
    k2.hp = 80;
    k2.attack = 5;
    k2.posY = 1;
    k2.posX = 1;

    k1.Move(2, 2);
    k1.Attack();
    k1.Die();

    return 0;
}
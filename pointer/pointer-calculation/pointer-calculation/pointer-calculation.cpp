#include <iostream>
using namespace std;

// 포인터 연산
// 
// 1) 주소 연산자 (&)
// 2) 산술 연산자 (+ -)
// 3) 간접 연산자
// 4) 간접 멤버 연산자

struct Player
{
    int hp;
    int damage;
};

int main()
{
    int number = 1;

    // 1) 주소 연산자 (&)
    int* pointer = &number;

    // 2) 산술 연산자 (+ -)
    // number = number + 1;
    // number++;
    // ++number;
    number += 1;

    // pointer = pointer + 1;
    // pointer++;
    // ++pointer;
    //pointer += 1;

    // 3) 간접 연산자 (*)
    // pointer += 1;을 주석처리 후 진행해야 확인할 수 있다.
    number = 5;
    cout << number << endl;
    *pointer = 3;
    cout << number << endl;

    Player player;
    player.hp = 100;
    player.damage = 10;

    Player* playerPtr = &player;
    (*playerPtr).hp = 200;
    (*playerPtr).damage = 200;

    // 4) 간접 멤버 연산자 (->)
    playerPtr->hp = 200;
    playerPtr->damage = 200;
}
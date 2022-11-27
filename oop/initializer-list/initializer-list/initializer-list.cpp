#include <iostream>
using namespace std;

// 초기화 리스트

// 멤버 변수를 초기화 하는 방법에는 다양한 문법이 존재한다.

// 초기화는 왜 해야할까?
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우 더욱 중요

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트 (V)
// - C++11 문법

// 초기화 리스트
// - 상속 관계에서 원하는 부모 생성자를 호출할 때 필요하다.
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다.
// -- 정의함과 동시에 초기화가 필요한 경우 (참조 타입, const 타입)

// 생성자 내보에서 하는 것보단 초기화 리스트 사용 방식이 조금 더 좋다.

class Inventory
{
public:
    Inventory() { cout << "Inventory()" << endl; }
    Inventory(int size) {
        cout << "Inventory(int size)" << endl;
        _size = size;
    }

    ~Inventory() { cout << "~Inventory()" << endl; }
public:
    int _size = 10;
};

class Player
{
public:
    Player() { }
    Player(int id) { }
};

// Is-A (Knight Is-A Player? 기사는 플레이어인가?) OK -> 상속관계
// Is-A (Knight Is-A Inventory? 기사는 인벤토리인가?) NO

// Has-A (Knight Has-A Inventory? 기사는 인벤토리를 갖고 있는가?) OK -> 포함관계
class Knight : public Player
{
public:
    Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
        /*
        선처리 영역
        Inventory()
        */
    {
        // _hp = 100;
        // _inventory = Inventory(20);
    }
public:
    int _hp;
    Inventory _inventory;

    int* _hpPtr;    // 초기화 굳이 필요없음

    // 무조건 초기화 되어있어야 함
    int& _hpRef;
    const int _hpConst;
};

int main()
{
    Knight k;

    cout << k._hp << endl;  // 초기화 안 하면 쓰레기 값 들어감(-858993460)

    return 0;
}
#include <iostream>
using namespace std;

// 생성자(Constructor)와 소멸자(Destructor)

// 시작과 끝을 알리는 함수를 각각 생성자, 소멸자라고 한다.
// - 시작(탄생) -> 생성자 : 여러개 존재 가능
// - 끝(소멸) -> 소멸자 : 오직 1개만 

// 암시적(Implicit) 생성자
// 생성자를 명시적으로 만들지 않으면
// 아무 인자도 받지 않는 기본 생성자가 컴파일러에 의해 자동으로 만들어짐
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자를 하나 만들면
// 자동으로 만들어지던 기본 생성자는 더 이상 만들어지지 않는다.

class Knight
{
public:
    // [1] 기본 생성자 (인자가 없음)
    Knight()
    {
        cout << "Knight() 기본 생성자 호출" << endl;

        _hp = 100;
        _attack = 10;
        _posY = 0;
        _posX = 0;
    }

    // [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
    // 일반적으로 똑같은 데이터를 지닌 객체가 생성되길 기대한다.
    Knight(const Knight& knight)
    {
        _hp = knight._hp;
        _attack = knight._attack;
        _posY = knight._posY;
        _posX = knight._posX;
    }

    // [3] 기타 생성자
    // 이 중에서 인자를 하나만 받는 기타 생성자를
    // 타입 변환 생성자라고 부르기도 함

    // 명시적인 용도로만 사용할 것!
    explicit Knight(int hp)
    {
        cout << "Knight(int) 생성자 호출" << endl;
        _hp = hp;
        _attack = 10;
        _posY = 0;
        _posX = 0;
    }

    Knight(int hp, int attack, int posX, int posY)
    {
        _hp = hp;
        _attack = attack;
        _posY = posY;
        _posX = posX;
    }

    // 소멸자
    ~Knight()
    {
        cout << "Knight() 소멸자 호출" << endl;
    }

    // 멤버 함수 선언
    void Move(int y, int x);
    void Attack();
    // 클래스 내에서 바로 구현 가능
    void Die()
    {
        _hp = 0;
        this->_hp = 1;
        cout << "Die" << endl;
    }
public:
    // 멤버 변수
    int _hp;
    int _attack;
    int _posY;
    int _posX;
};

// 멤버 함수 구현
void Knight::Move(int y, int x)
{
    _posY = y;
    _posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack : " << _attack << endl;
}

void HelloKnight(Knight k)
{
    cout << "Hello Knight" << endl;
}

int main()
{
    // 객체의 사용
    Knight k1;
    /*
    * 생성자에서 초기값 세팅
    k1._hp = 100;
    k1._attack = 10;
    k1._posY = 0;
    k1._posX = 0;
    */

    Knight k2(k1);

    // 생성함과 동시에 복사
    Knight k3 = k1;

    // 생성한 후 복사
    Knight k4;
    k4 = k1;

    k1.Move(2, 2);
    k1.Attack();
    k1.Die();

    // 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
    int num = 1;

    float f = (float)num;   // 명시적
    double d = num; // 암시적

    Knight k5;
    k5 = (Knight)1;

    cout << "k5 hp : " << k5._hp << endl;

    //HelloKnight(5);

    return 0;
}
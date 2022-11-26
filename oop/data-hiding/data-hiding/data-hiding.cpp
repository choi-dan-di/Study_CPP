#include <iostream>
using namespace std;

// 은닉성

// 객체 지향 프로그래밍(OOP : Object Oriented Programming)
// - 상속성
// - 은닉성 (V)
// - 다형성

// 은닉성(Data Hiding) == 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다는 의미
// 숨기는 이유?
// - 1) 정말 위험하고 건드리면 안 되는 경우
// - 2) 다른 경로로 접근하길 원하는 경우

// 1) 정말 위험하고 건드리면 안 되는 경우
// 자동차를 설계해보기
class Car
{
public:
    void MoveHandle() {}
    void PushPedal() {}
    void OpenDoor() {}

    void TurnKey() {
        RunEngine();
    }

protected:
    // 외부에서 건드리면 안 되는 것들
    void DisassembleCar() {}    // 차를 분해한다.
    void RunEngine() {} // 엔진을 구동시킨다.
    void ConnectCircuit() {}    // 전기선을 연걸시킨다.

public:
    // 핸들
    // 페달
    // 엔진
    // 문
    // 각종 전기선
};

/*
class SuperCar : public Car     // 상속 접근 지정자
{
public:
    void PushRemoteController()
    {
        // private은 사용불가. protected는 사용 가능
        RunEngine();
    }
};
*/

// private 상속
class SuperCar : private Car
{
public:
    void PushRemoteController()
    {
        // 나 까지만 사용하고 막아버릴 것임.
        RunEngine();
    }
};

class TestSuperCar : SuperCar
{
public:
    void PushRemoteController()
    {
        // 사용 불가능
        // RunEngine();
    }
};

// 2) 다른 경로로 접근하길 원하는 경우
class Berserker
{
public:
    int GetHp() { return _hp; }

    void SetHp(int hp)
    {
        _hp = hp;
        if (_hp <= 50)
            SetBerserkerMode();
    }

    // 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)
private:
    void SetBerserkerMode()
    {
        cout << "매우 강해짐!" << endl;
    }

private:
    int _hp = 100;
};

int main()
{
    Car car;

    //car.DisassembleCar();

    Berserker b;


    return 0;
}
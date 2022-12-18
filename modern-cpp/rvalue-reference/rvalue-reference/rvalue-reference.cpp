#include <iostream>
using namespace std;

// 오른값 참조 (rvalue reference)와 std::move
// 이 문법의 탄생 전후로 C++의 속도가 확연히 차이나게 되었다.

class Pet {

};

class Knight {
public:
    Knight() {
        cout << "Knight()" << endl;
    }

    // 직접 구현해주지 않으면 기존값 그대로 복사된다. -> 얕은 복사가 되며 여러 기사가 같은 펫을 가리키게 된다.
    // 복사 생성자
    Knight(const Knight& knight) {
        cout << "const Knight&" << endl;
    }

    ~Knight() {
        if (_pet)
            delete _pet;
    }

    // 복사 대입 연산자
    void operator=(const Knight& knight) {
        cout << "operator=(const Knight&)" << endl;

        // 깊은 복사
        _hp = knight._hp;

        if (knight._pet)
            _pet = new Pet(*knight._pet);
    }

    // 이동 생성자
    Knight(Knight&& knight) {
        cout << "Knight&&" << endl;
    }

    // 이동 대입 연산자
    void operator=(Knight&& knight) noexcept {
        cout << "operator=(copnst Knight&&)" << endl;

        // 얕은 복사
        _hp = knight._hp;
        _pet = knight._pet;

        // 오른값의 정보를 수정할 수 있다.
        knight._pet = nullptr;
    }

    void PrintInfo() const {

    }
public:
    int _hp = 100;
    Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) { }
void TestKnight_LValueRef(Knight& knight) { }
void TestKnight_ConstLValueRef(const Knight& knight) {
    knight.PrintInfo();
}

// 오른값 참조
// &&가 붙어서 새로운 의미가 된다.
// 오른값 참조를 사용하더라도 원본값이 변경된다.
// 이동 대상이 된다. -> 원본 데이터가 유지되지 않아도 된다.
// 
void TestKnight_RValueRef(Knight&& knight) { }

int main()
{
    // 왼값(lvalue) vs 오른값(rvalue)
    // - lvalue : 단일식을 넘어서 계속 지속되는 개체
    // - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

    Knight k1;

    TestKnight_Copy(k1);
    TestKnight_LValueRef(k1);
    // 임시 객체 생성과 동시에 넘겨준다는 의미. 오른값이기 때문에 건네줄 수 없다.
    // TestKnight_LValueRef(Knight());
    TestKnight_ConstLValueRef(Knight());

    // 오른값 참조는 왼값을 받아줄 수 없다.
    // TestKnight_RValueRef(k1);
    TestKnight_RValueRef(Knight());
    TestKnight_RValueRef(static_cast<Knight&&>(k1));

    Knight k2;
    k2._pet = new Pet();
    k2._hp = 1000;

    // 더 이상 k2는 사용하지 않는다. -> 원본은 날려도 된다는 Hint를 주는 쪽에 가깝다.
    // 복사가 아닌 '이동'에 가까운 의미
    // 특수 상황에서 사용하고 일반적으로는 오른값 캐스팅을 멋대로 해서는 안 된다.
    Knight k3;
    k3 = static_cast<Knight&&>(k2);

    // std::move
    // 위의 이동 연산과 동일하게 동작한다.
    Knight k4;
    k4 = move(k3);  // 오른값 참조로 캐스팅
    // std::move의 본래 이름 후보 중 하나가 rvalue_cast

    // 참고
    Knight* k;
    // 오로지 하나만 존재하는 포인터
    // 복사 불가
    unique_ptr<Knight> uptr = make_unique<Knight>();
    // 소유권 이전의 개념. 이동 후 uptr은 소멸된다.
    unique_ptr<Knight> uptr2 = move(uptr);


    return 0;
}
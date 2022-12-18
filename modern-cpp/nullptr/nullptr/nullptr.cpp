#include <iostream>
using namespace std;

// nullptr

class Knight {
public:
    void Test() {

    }
};

Knight* FindKnight() {
    // TODO

    return nullptr;
}

void Test(int a) {
    cout << "Test(int)" << endl;
}

void Test(void* ptr) {
    cout << "Test(*)" << endl;
}

// nullptr 구현
const
class {
public:
    // 그 어떤 타입의 포인터와도 치환 가능
    template<typename T>
    operator T* () const {
        return 0;
    }

    // 그 어떤 타입의 멤버 포인터와도 치환 가능
    template<typename C, typename T>
    operator T C::* () const {
        return 0;
    }

private:
    void operator&() const; // 주소값 &를 막는다.
} _nullPtr;

int main()
{
    // 예전 코드
    int* ptr = NULL; // 0 NULL

    // 1) 오동작 방지
    // 둘 다 윗버전이 호출됨. 위험함
    // NULL도 int 타입으로 받아버리면 로직이 꼬일 수 있기 때문
    Test(0);
    Test(NULL);
    // nullptr -> 오동작을 방지하기 위함
    Test(_nullPtr);

    // 2) 가독성
    // 가독성 측면에서 좋다. -> 포인터인지 단 번에 알 수 있음
    auto knight = FindKnight();
    if (knight == _nullPtr) {

    }

    nullptr_t whoami = nullptr;

    // 멤버 함수 포인터
    void (Knight:: * memFunc)();
    memFunc = &Knight::Test;

    if (memFunc == _nullPtr) {

    }

    return 0;
}
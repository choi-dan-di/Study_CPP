#include <iostream>
using namespace std;

// 전달 참조 (forwarding reference)

class Knight {
public:
    Knight() { cout << "기본 생성자" << endl; }
    Knight(const Knight& knight) { cout << "복사 생성자" << endl; }
    Knight(Knight&& knight) noexcept { cout << "이동 생성자" << endl; }
};

// 오른값 참조
void Test_RValueRef(Knight&& k) {

}

void Test_Copy(Knight k) {

}

// 전달 참조
template<typename T>
void Test_ForwardingRef(T&& param) {
    // TODO
    // 만약 넘겨받은 param이 왼값 참조라면 복사 형태로, 오른값 참조라면 이동 형태로 작동되어야한다.
    // std::forward를 이용하면 알아서 구분해준다.
    Test_Copy(forward<T>(param));
}

int main()
{
    // 이전 이름 : 보편 참조 (universal reference)
    // 현재 이름 : 전달 참조 (forwarding reference) C++17

    // 오른값 참조(&&)와 비슷하게 생김.
    // &&    &를 두 번 -> 오른값 참조

    Knight k1;

    Test_RValueRef(move(k1));   // rvalue_cast

    // 왼값 참조
    //Test_ForwardingRef(k1);
    // 오른값 참조
    //Test_ForwardingRef(move(k1));

    // 왼값 참조
    auto&& k2 = k1;
    // 오른값 참조
    auto&& k3 = move(k1);

    // 전달 참조를 구별하는 방법
    
    // 형식 연역(type deduction)이 일어날 때 전달 참조 방식으로 진행될 수 있다.
    // -> template이나 auto와 사용할 때
    // -> 왼값을 전달해주면 왼값 참조, 오른값을 전달해주면 오른값 참조
    // const 등 추가적으로 다른 타입이 붙으면 오른값 참조로 고정된다.

    // ----------------------------------------------------

    Knight& k4 = k1;    // 왼값 참조
    Knight&& k5 = move(k1); // 오른값 참조

    // 오른값 : 왼값이 아니다 = 단일식에서 벗어나면 사용 불가능한 것들
    // 오른값 참조 : 오른값만 참조할 수 있는 참조 타입
    //Test_RValueRef(move(k5));

    Test_ForwardingRef(k1);
    Test_ForwardingRef(move(k1));


    return 0;
}
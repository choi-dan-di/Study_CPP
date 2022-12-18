#include <iostream>
#include <vector>
#include <map>
using namespace std;

// auto

class Knight {
public:
    int _hp;
};

template<typename T>
void Print(T t) {
    cout << t << endl;
}

int main()
{
    // Modern C++ (C++11 이후)

    // int a = 3;
    // float b = 3.14f;
    // double c = 1.23;
    // Knight d = Knight();
    // const char* e = "Dandi";

    auto a = 3;
    auto b = 3.14f;
    auto c = 1.23;
    auto d = Knight();
    auto e = "Dandi";

    // auto는 일종의 조커카드
    Print(1);
    Print("Dandi");

    // 형식 연역 (type deduction)
    // -> 추론
    // 추론 규칙은 생각보다 복잡해질 수 있다.
    auto f = &d;    // Knight*
    const auto test1 = b;   // const float
    auto* test2 = e;    // const char*
    // auto* test3 = a;    // 할 수 없음

    // 주의!
    // 기본 auto는 [const, &]를 무시한다.
    int& reference = a;
    const int cst = a;

    auto test4 = reference; // int
    auto test5 = cst;   // int

    // 예시
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (vector<int>::size_type i = 0; i < v.size(); i++) {
        int& data = v[i];
        // auto data = v[i];    // 의미가 완전 달라짐
        // auto를 사용하고 싶다면 아래처럼 사용해야 한다.
        // auto& data = v[i];
        // auto data = static_cast<int&>(v[i]);
        data = 100;
    }

    // 아무튼 이제 기존의 타입은 잊어버리고 auto만 사용할래요!
    // 선호하지 않는다. 케바케
    // -> 타이핑이 길어지는 경우엔 OK
    // -> 가독성을 위해 일반적으로는 놔두는 게 좋다.

    map<int, int> m;
    auto ok = m.insert(make_pair(1, 100));

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    return 0;
}
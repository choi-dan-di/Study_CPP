#include <iostream>
using namespace std;

// delete (삭제된 함수)

class Knight {
public:

// 예전 문법
private:
    // 정의되지 않은 비공개(private) 함수
    void operator=(const Knight& k) {

    }
    // 이 아이 한정 허용
    friend class Admin;
    friend void Print(const Knight& k);
// 현재 문법
//public:
//    // 내가 명시적으로 사용을 안 하겠다고 선언한 의미이다.
//    void operator=(const Knight& k) = delete;
private:
    int _hp = 100;
};

class Admin {
public:
    void CopyKnight(const Knight& k) {
        Knight k1;
        // 복사 연산
        k1 = k;
    }
};

void Print(const Knight& k) {
    cout << k._hp << endl;
}

int main()
{
    Knight k1;

    Knight k2;

    // 복사 연산자
    // k1 = k2;

    Admin admin;
    admin.CopyKnight(k1);

    Print(k1);

    return 0;
}
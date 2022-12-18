#include <iostream>
#include <vector>
using namespace std;

// 중괄호 초기화 { }

class Knight {
public:
    Knight() {

    }

    Knight(int a, int b) {
        cout << "Knight(int, int)" << endl;
    }

    // 우선순위 짱
    Knight(initializer_list<int> li) {
        cout << "Knight(initializer_list)" << endl;
    }
 };

int main()
{
    // 중괄호 초기화 { }
    // 다양한 초기화 방법
    int a = 0;
    int b(0);
    int c{ 0 };

    Knight k1;
    Knight k2 = k1; // 복사 생성자 (대입 연산자 아님)

    Knight k3;  // 기본 생성자
    k3 = k1;    // 대입 연산자

    Knight k4{ k2 };

    // 다른 초기화 방법과 어떤 차이가 있나?
    // -> 다양한 초기화 방법을 통일시켜주기 위해 만들어짐
    // -> 초기화 값이 각기 다를 때 초기화할 방법이 없었음 (배열 제외)

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2(10, 1);

    int arr[] = { 1, 2, 3, 4 };

    // 중괄호 초기화 방법
    // 1) vector 등의 컨테이너와 잘 어울린다.
    vector<int> v3{ 1, 2, 3, 4 };

    // 2) 축소 변환을 방지한다.
    int x = 0;
    double y{ x };  // 에러남

    // 축소 변환이란?


    // 3) Bonus
    Knight k5();    // 기본 생성자가 호출되는 게 아닌 k5의 함수를 선언하는 문법과 동일하다.
    // 헷갈림 방지
    Knight k6{ };   // 기본 생성자로 생성

    // 중괄호 초기화 단점
    // 어떤 생성자를 호출할지 애매해진다.
    Knight k7{ 1, 2 };
    Knight k8(1, 2);

    // 기준을 두 가지로 나눌 수 있다.
    
    // 괄호 초기화 ( ) 를 기본으로 간다.
    // - 전통적인 C++ (거부감이 없음)
    // - vector 등 특이한 케이스에 대해서만 중괄호 초기화 { } 를 사용한다.

    // 중괄호 초기화 { } 를 기본으로 간다.
    // - 초기화 문법의 일치화
    // - 축소 변환 방지


    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// 벡터(vector)

int main()
{
    // STL (Standard Template Library)
    // 프로그래밍할 때 필요한 자료구조/알고리즘들을
    // 템플릿으로 제공하는 라이브러리

    // 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

    // vector (동적 배열)
    // - vector의 동작 원리 (size/capacity) V
    // - 중간 삽입/삭제
    // - 처음/끝 삽입/삭제
    // - 임의 접근

    // 배열
    // 단점 : 크기를 유동적으로 관리하기 힘들며 데이터의 추가 삭제가 어렵다.
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE] = {};

    for (int i = 0; i < MAX_SIZE; i++)
        arr[i] = i;

    for (int i = 0; i < MAX_SIZE; i++)
        cout << arr[i] << endl;

    // 동적 배열
    // 매우 매우 중요한 개념 -> 어떻게 배열을 '유동적으로' 사용한 것인가?

    // 1) (여유분을 두고) 메모리를 할당한다.
    // 2) 여유분까지 꽉 찼으면 메모리를 증설한다.

    // Q1) 여유분은 얼만큼이 적당할까?
    // Q2) 증설을 얼만큼 해야 할까?
    // Q3) 기존의 데이터를 어떻게 처리할까?

    cout << "------------------------------------\n";

    vector<int> v;
    vector<int> v2(1000, 0);    // resize 1000, value 0
    vector<int> v3 = v2;
    /*
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    */

    for (int i = 0; i < 1000; i++) {
        v.push_back(100);
        cout << v.size() << " " << v.capacity() << endl;
    }

    cout << "------------------------------------\n";
    
    // size (실제 사용 데이터 개수)
    // 1 2 3 4 5 6 7 ...
    // capacity (여유분을 포함한 용량 개수) : 컴파일러마다 다르지만 대략적으로 1.5배씩 증가
    // 늘어는 나지만 줄어들지는 않는다.
    // /1 2 3 4 6 9 13 19 28 42 63 ...

    // capacity를 설정해주는 함수
    v.reserve(1000);
    // size를 설정해주는 함수
    v.resize(1000);
    
    // v.capacity();

    /*
    const int size = v.size();
    for (int i = 0; i < size; i++)
        cout << v[i] << endl;
    */

    // 배열의 가장 첫 요소
    cout << v.front() << endl;
    // 배열의 가장 마지막 요소
    cout << v.back() << endl;
    cout << v.size() << " " << v.capacity() << endl;
    // 배열의 가장 마지막 요소 삭제
    v.pop_back();
    cout << v.back() << endl;
    cout << v.size() << " " << v.capacity() << endl;

    // 벡터 내의 모든 데이터를 날려주는 함수
    v.clear();
    // capacity도 날리고 싶으면 swap 함수를 이용한다.
    vector<int>().swap(v);
    cout << v.size() << " " << v.capacity() << endl;

    return 0;
}
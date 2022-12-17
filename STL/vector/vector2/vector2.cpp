#include <iostream>
#include <vector>
using namespace std;

// 벡터(vector)2

int main()
{
    // STL (Standard Template Library)
    // 프로그래밍할 때 필요한 자료구조/알고리즘들을
    // 템플릿으로 제공하는 라이브러리

    // 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

    // vector (동적 배열)
    // - vector의 동작 원리 (size/capacity)
    // - 중간 삽입/삭제 V
    // - 처음/끝 삽입/삭제 V
    // - 임의 접근 V

    // 반복자 (Iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로도 이동이 가능하다.
    
    vector<int> v(10);
    v.reserve(1000);

    for (vector<int>::size_type i = 0; i < v.size(); i++)
        v[i] = i;

    // 포인터와 비교해보기
    //vector<int>::iterator it;
    //int* ptr;

    //// iterator type 반환. 벡터의 첫 요소의 iterator값을 반환하는 듯.
    //it = v.begin();
    //ptr = &v[0];

    //cout << (*it) << endl;
    //cout << (*ptr) << endl;

    //it++;
    //++it;
    //ptr++;
    //++ptr;

    //it--;
    //--it;
    //ptr--;
    //--ptr;

    //it += 2;
    //it = it - 2;
    //ptr += 2;
    //ptr = ptr - 2;

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << (*it) << endl;
    }

    cout << "-------------------------------------\n";

    int* ptrBegin = &v[0];  // v.begin()._Ptr;
    int* ptrEnd = ptrBegin + 10;    // v.end()._Ptr;
    for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr) {
        cout << (*ptr) << endl;
    }

    // 더 복잡해보이는데?
    // iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념이다.
    // 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안 될 수도 있다.
    // STL 한정, 통일성이 생기기 때문에 다른 자료구조로 넘어가기가 용이하다.

    // const int*;
    // 데이터 onlyread 할 경우 사용
    vector<int>::const_iterator cit1 = v.cbegin();
    // cit1 = 100; // 이동 불가

    cout << "-------------------------------------\n";

    // 역방향
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        cout << (*it) << endl;
    }

    // vector = 동적 배열 = 동적으로 커지는 배열 = 배열
    // 원소가 하나의 메모리 블록에 연속하게 저장된다. -> 데이터를 쉽게 찾기 위해서

    // - 중간 삽입/삭제 (BAD) : 배열에서는 굉장히 비효율적이다.
    // - 처음/끝 삽입/삭제 (BAD / GOOD)
    // -> 처음의 삽입/삭제는 중간 삽입/삭제와 똑같이 작동한다.
    // - 임의 접근 (Random Access) 지원
    // i번째 데이터는 어디 있습니까? 경우 접근이 쉽다.

    // 중간 삽입
    vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
    // 중간 삭제
    vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
    // 마지막은 포함 안 됨
    vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);

    // 벡터를 쭉 스캔 하면서 3이라는 데이터가 있으면 일괄 삭제하고 싶을 때
    for (vector<int>::iterator it = v.begin(); it != v.end();) {
        int data = *it;
        if (data == 3) it = v.erase(it);
        else ++it;
    }

    return 0;
}
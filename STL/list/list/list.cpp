#include <iostream>
#include <list>
using namespace std;

// 리스트(List)

// vector : 동적 배열

// 단일 / 이중 / 원형
// 단일 : [1] -> [2] -> [3] -> [4] -> [5]
// 이중 : [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [6] <-> [ _Myhead : end() ](더미 노드) <->
// 원형 : [1] <-> [2] <-> [3] <-> [4] <-> [5] <->
// list : 연결 리스트
// 데이터가 연속적으로 모여있지 않고 다음 데이터의 주소 정보만 담고 있다.
// 노드 형식
class Node {
public:
    Node* _next;
    Node* _prev;
    int _data;
};

int main()
{
    // list (연결 리스트)
    // - list의 동작 원리
    // - 중간 삽입/삭제 (GOOD / GOOD)
    // - 처음/끝 삽입/삭제 (GOOD / GOOD)
    // - 임의 접근 : 불가

    list<int> li;
    list<int>::iterator itRemember;
    for (int i = 0; i < 100; i++) {
        if (i == 50) itRemember = li.insert(li.end(), i);
        else li.push_back(i);
    }

    li.push_front(10);

    int size = li.size();
    // li.capacity();   // 없음

    int first = li.front();
    int last = li.back();

    // li[3] = 10;  // 없음

    list<int>::iterator itBegin = li.begin();
    list<int>::iterator itEnd = li.end();

    // 이터레이터 증감 : 1은 가능하지만 2 이상은 불가하다.
    // list<int>::iterator it2 = itBegin + 10;   // 안 됨

    // list<int>::iterator itTest1 = --itBegin; // X
    // list<int>::iterator itTest2 = --itEnd;   // O
    // list<int>::iterator itTest3 = ++itEnd;   // X

    int* ptrBegin = &(li.front());
    int* ptrEnd = &(li.back());

    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
        cout << (*it) << endl;

    li.insert(itBegin, 100);
    li.erase(li.begin());
    li.pop_front();
    // value가 10인 애들 일괄 삭제
    li.remove(10);

    // * 임의 접근이 안 된다
    // * 중간 삽입/삭제 빠르다 (?)
    // 50번 인덱스에 있는 데이터를 삭제해보기
    // li.erase(li.begin() + 50);
    /*
    list<int>::iterator it = li.begin();
    for (int i = 0; i < 50; i++)
        ++it;
    li.erase(it);
    */

    li.erase(itRemember);


    return 0;
}
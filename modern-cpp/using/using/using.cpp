#include <iostream>
#include <vector>
#include <list>
using namespace std;

// using

// typedef와 비슷하게 동작하나 문법이 약간 다르다.
typedef __int64 id;
using id2 = int;

// 1) 직관성이 뛰어남
// 함수 포인터
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 템플릿 활용이 가능하다.
// typedef은 템플릿을 활용할 수 없지만 using은 가능하다.
template<typename T>
using List = list<T>;

// 안 됨
/*
template<typename T>
typedef vector<T> List2;
*/
// using 이전 방법
template<typename T>
struct List2 {
    typedef list<T> type;
};

int main()
{
    id playerId = 0;

    List<int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);

    List2<int>::type li2;

    return 0;
}
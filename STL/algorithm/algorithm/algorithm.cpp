#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 알고리즘

void PrintFunc(int n) {
    cout << n << endl;
}

int main()
{
    // 자료구조 (데이터를 저장하는 구조)
    // 알고리즘 (저장한 데이터를 어떻게 사용할 것인가?)

    vector<int> v;

    int number = 50;

    for (int i = 0; i < 100; i++) {
        v.push_back(i);
    }

    // find
    // (시작 주소, 끝 주소 + 1, 찾을 대상)
    {
        vector<int>::iterator itFind = find(v.begin(), v.end(), number);
        if (itFind == v.end()) cout << "못 찾음" << endl;
        else cout << "찾음" << endl;
    }

    cout << "---------------------------------\n";

    // find_if
    // (시작 주소, 끝 주소 + 1, 조건식)
    {
        // 함수 객체 생성 -> 추후엔 람다식으로 간편하게 만들 수 있음.
        // 람다식 : [](int n) { return n % 11 == 0; }
        struct CanDivideBy11 {
            bool operator()(int n) {
                return n % 11 == 0;
            }
        };

        vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
        if (itFind == v.end()) cout << "못 찾음" << endl;
        else cout << "찾음" << endl;

        
    }

    cout << "---------------------------------\n";

    // count_if
    // (시작 주소, 끝 주소 + 1, 조건문)
    {
        struct IsOdd {
            bool operator()(int n) {
                return n % 2 != 0;
            }
        };

        int count = count_if(v.begin(), v.end(), IsOdd());
        cout << count << endl;

        // all_of : 모든 데이터가 조건을 만족하는가?
        // any_of : 조건을 만족하는 데이터가 하나라도 존재하는가?
        // none_of : 조건을 만족하는 데이터가 하나도 없는가?

        bool b1 = all_of(v.begin(), v.end(), IsOdd());
        bool b2 = any_of(v.begin(), v.end(), IsOdd());
        bool b3 = none_of(v.begin(), v.end(), IsOdd());

        cout << "b1 : " << b1 << ", b2 : " << b2 << ", b3 : " << b3 << endl;
    }

    cout << "---------------------------------\n";

    // for_each
    // 모든 데이터를 스캔할 때
    // (시작 주소, 끝 주소 + 1, 조건문
    {
        struct MultiplyBy3 {
            void operator()(int& n) {
                n *= 3;
                // 출력까지 하고 싶으면
                cout << n << endl;
            }
        };

        for_each(v.begin(), v.end(), MultiplyBy3());
    }

    // remove
    // remove_if
    {
        v.clear();

        v.push_back(1);
        v.push_back(4);
        v.push_back(3);
        v.push_back(5);
        v.push_back(8);
        v.push_back(2);

        struct IsOdd {
            bool operator()(int n) {
                return n % 2 != 0;
            }
        };

        // vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
        // v.erase(it, v.end());
        v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end());
    }

    

    return 0;
}
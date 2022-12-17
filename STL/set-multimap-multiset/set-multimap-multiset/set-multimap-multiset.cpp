#include <iostream>
#include <map>
#include <set>
using namespace std;

// set, multimap, multiset

int main()
{
    // set
    // 데이터가 곧 키일 때 사용. 이외의 특징은 맵과 동일하다.
    // (Key = Value)
    set<int> s;

    // 넣고
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(50);
    s.insert(40);
    s.insert(70);
    s.insert(90);
    s.insert(80);
    s.insert(100);
    s.insert(60);
    s.insert(60);

    // 빼고
    s.erase(40);

    // 찾고
    set<int>::iterator findIt = s.find(50);
    if (findIt == s.end()) cout << "못 찾음" << endl;
    else cout << "찾음" << endl;

    // 순회하고
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << (*it) << endl;

    // s[10] = 10;  // 문법상 맞지않음. 안 됨.

    // multimap
    // 키 값이 중복 허용되는 맵
    multimap<int, int> mm;

    // 넣고
    mm.insert(make_pair(1, 100));
    mm.insert(make_pair(1, 200));
    mm.insert(make_pair(1, 300));
    mm.insert(make_pair(2, 400));
    mm.insert(make_pair(2, 500));

    // mm[1] = 500; // 안 됨

    // 빼고
    // 해당 키 값을 가지고 있는 모든 원소 삭제
    unsigned int count = mm.erase(1);

    // 찾고
    multimap<int, int>::iterator findIt2 = mm.find(2);
    if (findIt2 != mm.end()) cout << "찾음 " << findIt2->first << " " << findIt2->second << endl;
    else cout << "못 찾음 " << findIt2->first << " " << findIt2->second << endl;

    cout << "-----------------------------------\n";

    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
    itPair = mm.equal_range(2);

    // begin, end와 비슷한 느낌
    multimap<int, int>::iterator itBegin = mm.lower_bound(1);  // 첫 주소 반환
    multimap<int, int>::iterator itEnd = mm.upper_bound(1);  // 마지막 주소의 다음 주소 반환

    for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
        cout << it->first << " " << it->second << endl;

    cout << "-----------------------------------\n";

    // 순회하고
    for (multimap<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
        cout << it->first << " " << it->second << endl;

    cout << "-----------------------------------\n";

    // multiset
    // 중복 허용되는 set
    multiset<int> ms;

    // 넣고
    ms.insert(100);
    ms.insert(100);
    ms.insert(100);
    ms.insert(200);
    ms.insert(200);

    // 빼고
    ms.erase(200);

    // 찾고
    multiset<int>::iterator findIt3 = ms.find(100);

    pair<multiset<int>::iterator, multiset<int>::iterator> itPair2;
    itPair2 = ms.equal_range(100);

    // begin, end와 비슷한 느낌
    multiset<int>::iterator itBegin2 = ms.lower_bound(100);  // 첫 주소 반환
    multiset<int>::iterator itEnd2 = ms.upper_bound(100);  // 마지막 주소의 다음 주소 반환

    cout << "-----------------------------------\n";

    for (multiset<int>::iterator it = itPair2.first; it != itPair2.second; ++it)
        cout << (*it) << endl;

    cout << "-----------------------------------\n";

    // 순회하고
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        cout << (*it) << endl;

    return 0;
}
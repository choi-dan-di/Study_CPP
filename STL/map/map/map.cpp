#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 맵(Map)

class Player {
public:
    Player() : _playerId(0) {

    }
public:
    int _playerId;
};

int main()
{
    // 연관 컨테이너

    vector<Player*> v;

    // 10만명 입장
    for (int i = 0; i < 100000; i++) {
        Player* p = new Player();
        v.push_back(p);
    }

    // 5만명 퇴장
    for (int i = 0; i < 50000; i++) {
        int randIndex = rand() % v.size();

        Player* p = v[randIndex];
        delete p;

        v.erase(v.begin() + randIndex);
    }

    // (ID = 2만 Player)가 (ID = 1만 Player)를 공격하고 싶어요.
    // Q) ID = 1만인 Player를 찾아주세요.
    // A) 위처럼 벡터로 플레이어 리스트를 만들면 반복문으로 찾는 수 밖에 없다.
    bool found = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->_playerId == 10000) {
            found = true;
            break;
        }
    }
    // -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다. (vector, list의 큰 단점)

    // => 이러한 단점을 보완하기 위해 map을 사용한다.
    
    // map : 균형 이진 트리 (AVL)
    // - 노드 기반
    class Node {
    public:
        Node* _left;
        Node* _right;
        // DATA
        pair<int, Player*> _data;
        // int _key;
        // Player* _value;
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    // (Key, Value)
    map<int, int> m;

    // insert 두 번 해보기 : 같은 키 값으로 추가할 순 없다. 두 번째 추가되는 코드가 무시된다.
    pair<map<int, int>::iterator, bool> ok;
    ok = m.insert(make_pair(1, 100));
    ok = m.insert(make_pair(1, 200));

    // ok.first;
    // ok.second;

    // 10만명 입장
    for (int i = 0; i < 100000; i++) 
        m.insert(pair<int, int>(i, i * 100));

    // 5만명 퇴장
    for (int i = 0; i < 50000; i++) {
        int randValue = rand() % 50000;

        // Erase By Key
        m.erase(randValue);
    }

    // Q) ID = 1만인 Player를 찾아주세요.
    // A) 맵을 이용하여 매우 빠르게 찾을 수 있다.
    // erase 두 번 해보기 : 이미 삭제되면 두 번째 코드는 무시된다.
    unsigned int count = m.erase(10000);
    count = m.erase(10000);

    map<int, int>::iterator findIt = m.find(10000);
    if (findIt != m.end()) cout << "찾음" << endl;
    else cout << "못 찾음" << endl;

    // map 순회
    // -> 이터레이터를 활용해야한다.
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        pair<const int, int>& p = (*it);
        // const int key = p.first;
        // const int key = it->first;
        // int value = p.second;
        // int value = it->second;

        // cout << (*it).first << " " << (*it).second << endl;
        cout << it->first << " " << it->second << endl;
    }

    // 없으면 추가, 있으면 수정 Ver.1
    map<int, int>::iterator findIt2 = m.find(10000);
    if (findIt != m.end()) findIt->second = 200;
    else m.insert(make_pair(10000, 200));

    // 없으면 추가, 있으면 수정 Ver.2
    m[10000] = 200;

    m.clear();

    // [] 연산자 사용할 때 주의할 점
    // 대입을 하지 않더라도 Key/Value 형태의 데이터가 추가된다.
    for (int i = 0; i < 10; i++)
        cout << m[i] << endl;

    // 넣고 (insert, [])
    // 빼고 (erase)
    // 찾고 (find, [])
    // 반복자 (map::iterator) (*it) pair<key, value>&

    return 0;
}
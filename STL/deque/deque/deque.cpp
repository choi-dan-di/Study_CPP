#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 덱(Deque)
// deque : double-ended queue

// 여유분을 모두 사용했을 때 새로운 메모리 구간을 할당받는다.
// 벡터와 리스트를 합친 것 같은 기능
// 양 옆으로 사용이 가능한 벡터 같은 느낌이 강함. -> 벡터쪽에 더 가까움
// [     ]
// [     ]
// [     ]

// 벡터
// [     ]
// [           ] (이사)

// 리스트
// [ ] <-> [ ] <-> [ ] <-> [ ] <-> ...

int main()
{
    // 시퀀스 컨테이너 (Sequence Container)
    // -> 데이터가 삽입 순서대로 나열되는 형태
    // vector, list, deque가 있다.

    deque<int> dq;

    dq.push_back(1);
    // dq.capacity();   // 없음
    dq.push_front(2);
    cout << dq[0] << endl;  // Random Access 가능

    // vector와 마찬가지로 배열 기반으로 동작한다.
    // 다만 메모리 할당 정책이 다르다.

    // vector와 비교해보기
    vector<int> v(3, 1);
    deque<int> d(3, 1);

    // vector
    // [1 1 1]

    // deque
    // [    3 3]
    // [1 1 1 2]
    // [2      ]
    v.push_back(2);
    v.push_back(2);

    d.push_back(2);
    d.push_back(2);

    d.push_front(3);
    d.push_front(3);

    // - deque의 동작 원리
    // - 중간 삽입/삭제 (BAD / BAD) : 벡터와 동일하게 동작한다. 어쩌면 훨씬 더 비효율적일수도?
    // - 처음/끝 삽입/삭제 (GOOD / GOOD)
    // - 임의 접근 : 지원(GOOD)

    return 0;
}
#include <iostream>
using namespace std;

// 동적 할당

// 메모리 구조 복습
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global)/정적(static) 변수 -> 데이터 영역
// - 지역 변수/매개 변수 -> 스택 영역
// 
// - 동적 할당 -> 힙 영역 (V)

// 실제 상황)
// - MMORPG 동접 1명 ~ 5만명, 몬스터 1마리 ~ 500만 마리
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// - 스택 영역
// -- 함수가 끝나면 같이 정리되는 불안정한 메모리
// -- 잠시 함수에 매개변수를 넘긴다거나 하는 용도로는 사용하기 좋다.
// - 메모리 영역
// -- 프로그램이 실행되는 도중에는 무조건 사용되는 공간

// 희망사항)
// - 필요할 때만 사용하고, 필요없으면 반납할 수 있는 공간
// - 그러면서도 (스택과는 다르게) 우리가 생성/소멸 시점을 관리할 수 있는 공간
// -> Heap 영역
// 동적 할당과 연관된 함수/연산자 : malloc/free, new/delete, new[]/delete[]

// malloc
// - 할당할 메모리 크기를 건네준다.
// - 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다. (메모리 부족하면 nullptr 반환)

// free
// - malloc (혹은 기타 calloc, realloc 등의 사촌)을 통해 할당된 영역을 해제할 때 사용
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// new / delete
// - C++에서 추가됨
// - malloc/free는 함수이지만 new/delete는 연산자(operator)이다.

// new[] / delete[]
// - new가 malloc에 비해 좋긴 한데, 배열과 같이 n개 데이터를 동시에 할당하려면?

// malloc/free vs new/delete
// - 사용 편의성 -> new/delete 승!
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받으려면? -> malloc/free 승!

// 그런데 둘의 가장 가장 근본적인 중요한 차이는 따로 있음!
// new/delete는 (생성타입이 클래스일 경우) 생성자/소멸자를 호출해준다!!!


class Monster
{
public:
    Monster()
    {
        _hp = 0;
        _x = 0;
        _y = 0;
        cout << "Monster() 호출" << endl;
    }

    ~Monster()
    {
        cout << "~Monster() 호출" << endl;
    }
public:
    int _hp;
    int _x;
    int _y;
};

//Monster monster[500 * 10000];

int main()
{
    // 몬스터를 만드는 방법 1
    // 디버그 시 스택 오버플로우 에러 발생
    // Monster monster[500 * 10000];

    // 유저 영역 [메모장] [LOL] [곰플레이어] : 독립적으로 실행
    // ------------------------------------------
    // 커널 영역 (Windows 등의 핵심 코드) : 유저 영역에서 메모리 요청 시 메모리 관리를 해주는 곳

    // 유저 영역 : 운영체제에서 제공하는 API 호출
    // 커널 영역 : 메모리 할당해서 건네줌

    // C++에서는 기본적으로 CRT(C 런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
    // 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음 (MMORPG 서버 메모리 풀링)

    // malloc/free-------------------------------------------------
    // 메모리 할당
    //void* pointer = malloc(1000);
    void* pointer = malloc(sizeof(Monster));

    // void*는 무엇일까?
    // *가 있으니 포인터는 포인터 (주소를 담는 바구니) => OK
    // 타고 가면 void 아무것도 없다 ? => NO
    // 타고 가면 void 뭐가 있는지 모르겠으니까 적당히 변환해서 사용해라 => OK
    Monster* m1 = (Monster*)pointer;
    m1->_hp = 100;
    m1->_x = 1;
    m1->_y = 2;

    Monster* m2 = (Monster*)malloc(sizeof(Monster));
    m2->_hp = 200;
    m2->_x = 2;
    m2->_y = 4;

    // 메모리 할당 해제
    free(pointer);
    free(m2);

    // Heap Overflow
    // - 유효한 힙 범위를 초과해서 사용하는 문제
    // void* pointer = malloc(4);

    // 메모리 할당 해제하지 않으면 메모리 누수 발생
    
    // Double free
    // 메모리 할당해제 여러번 하는 것
    // 대부분 그냥 크래시만 나고 끝난다.
    //free(pointer);

    // Use-After-Free
    // 바로 크래시가 나지 않고 다른 부분을 건드리게 되기 때문에 위험하다
    // - 프로그래머 입장 : 망했다!
    // - 해커 입장 : 심봤다!
    // m1->_hp = 100;
    // m1->_x = 1;
    // m1->_y = 2;

    // new/delete-------------------------------------------------
    // 메모리 할당
    Monster* m3 = new Monster;
    m3->_hp = 300;
    m3->_x = 3;
    m3->_y = 6;

    // 메모리 할당 해제
    delete m3;

    // new[]/delete[]-------------------------------------------------
    Monster* m4 = new Monster[5];
    m4->_hp = 400;
    m4->_x = 4;
    m4->_y = 8;

    Monster* m5 = (m4 + 1);
    m5->_hp = 500;
    m5->_x = 5;
    m5->_y = 10;

    delete[] m4;
    //delete m5;

    return 0;
}
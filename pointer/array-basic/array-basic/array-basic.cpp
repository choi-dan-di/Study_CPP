#include <iostream>
using namespace std;

// 배열

struct StatInfo {
    int hp = 0xAAAAAAAA;
    int attack = 0xBBBBBBBB;
    int defence = 0xDDDDDDDD;
};

void Test(int a) {
    a++;
}

// 배열을 함수 인자로 넘기면 컴파일러가 알아서 포인터로 치환한다.
// 즉 배열의 내용 전체를 넘긴 게 아니라, 시작 주소(포인터)만 넘긴 것
void Test(char a[]) {
    a[0] = 'Z';
}

int main()
{
#pragma region 배열
    // type 이름[개수]
    StatInfo monsters[10];  // StatInfo 타입의 monsters라는 배열. 크기는 10이다.

    // VC 컴파일러 기준, 배열의 크기는 상수여야 한다.
    const int monsterCount = 10;
    StatInfo monsters2[monsterCount];

    // 배열의 이름은 조금 다르게 동작한다.
    StatInfo players[10];
    // players = monsters;  // 사용 불가

    // 배열의 이름은 곧 배열의 시작 주소이다.
    // 정확히는 시작 위치를 가리키는 type* 포인터라고 볼 수 있다.
    auto whoAmI = monsters; // StatInfo* whoAmI

    StatInfo* monster_0 = monsters;
    monster_0->hp = 100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    // 포인터의 덧셈 -> 다음 주소로 이동
    StatInfo* monster_1 = monsters + 1;
    monster_1->hp = 200;
    monster_1->attack = 20;
    monster_1->defence = 2;

    // 포인터와 참조는 자유자재로 변환 가능하다.
    StatInfo& monster_2 = *(monsters + 2);
    monster_2.hp = 300;
    monster_2.attack = 30;
    monster_2.defence = 3;

    // [주의] 이것은 완전 다른 의미이다.
    StatInfo temp = *(monsters + 2);
    temp.hp = 300;
    temp.attack = 30;
    temp.defence = 3;

    // 이를 조금 더 자동화한다.
    for (int i = 0; i < 10; i++) {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = 1 * (i + 1);
    }

    // 인덱스를 사용하면 보다 편리하게 배열을 관리할 수 있다.
    monsters[0].hp = 100;
    monsters[0].attack = 10;
    monsters[0].defence = 1;

    for (int i = 0; i < 10; i++) {
        monsters[i].hp = 100 * (i + 1);
        monsters[i].attack = 10 * (i + 1);
        monsters[i].defence = 1 * (i + 1);
    }

    // 배열 초기화 문법 몇가지
    int numbers[5] = {};    // 모두 0으로 설정
    int numbers2[10] = { 1, 2, 3, 4, 5 };   // 1,2,3,4,5 설정 후 나머지는 0으로 설정
    int numbers3[] = { 1, 2, 3, 4, 11, 24 }; // 데이터 개수만큼의 크기의 배열 설정
    char helloStr[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << helloStr << endl;
#pragma endregion

#pragma region 포인터 vs 배열
    // 문자열 비교
    const char* test1 = "Hello World";
    char test2[] = "Hello World";
    test2[0] = 'R';

    cout << test2 << endl;

    // 배열을 함수의 인자로 넘기게 되면?
    int a = 0;
    Test(a);
    cout << a << endl;

    // test2가 바뀔까, 안 바뀔까? -> 바뀐다!
    Test(test2);
    cout << test2 << endl;
#pragma endregion
    return 0;
}

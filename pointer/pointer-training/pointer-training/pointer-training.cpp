#include <iostream>
using namespace std;

// 포인터 실습

// 간단하게 textRPG 만들어보기
struct StatInfo
{
    int hp; // +0 (주소)
    int attack; // +4
    int defence;    // +8
};

void EnterLobby();

// 차이를 보기 위해 다르게 만듦
// 포인터 이전 버전
StatInfo CreatePlayer();
// 포인터 이후 버전
void CreateMonster(StatInfo* info);

// 플레이어 승리 유무 리턴 (승 : true, 패 : false)
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
    EnterLobby();
}

void EnterLobby()
{
    cout << "로비에 입장했습니다." << endl;

    // 플레이어 생성
    StatInfo player;

    // 메모리를 편하게 살펴보기 위해 임의의 값 세팅
    player.hp = 0xbbbbbbbb;
    player.attack = 0xbbbbbbbb;
    player.defence = 0xbbbbbbbb;

    player = CreatePlayer();

    // 몬스터 생성
    StatInfo monster;

    // 메모리를 편하게 살펴보기 위해 임의의 값 세팅
    monster.hp = 0xbbbbbbbb;
    monster.attack = 0xbbbbbbbb;
    monster.defence = 0xbbbbbbbb;

    CreateMonster(&monster);
    
    // 번외
    // 구조체끼리 복사할 때 무슨 일이 벌어질까?
    // player = monster;

    bool victory = StartBattle(&player, &monster);

    if (victory)
        cout << "승리!" << endl;
    else
        cout << "패배!" << endl;
}

StatInfo CreatePlayer()
{
    StatInfo ret;

    cout << "플레이어 생성" << endl;
    // 플레이어 세팅
    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    return ret;
}

void CreateMonster(StatInfo* info)
{
    cout << "몬스터 생성" << endl;
    // 몬스터 세팅
    info->hp = 40;
    info->attack = 8;
    info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
    while (true)
    {
        int damage = player->attack - monster->defence;
        if (damage < 0)
            damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0)
            monster->hp = 0;

        cout << "몬스터 HP : " << monster->hp << endl;

        if (monster->hp == 0)
            return true;

        damage = monster->attack - player->defence;
        if (damage < 0)
            damage = 0;

        player->hp -= damage;
        if (player->hp < 0)
            player->hp = 0;

        cout << "플레이어 HP : " << player->hp << endl;

        if (player->hp == 0)
            return false;
    }
}
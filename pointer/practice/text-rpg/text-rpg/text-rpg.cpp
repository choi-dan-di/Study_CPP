#include <iostream>
using namespace std;

// TextRPG
// 스택 프레임을 활용하여 만들어보기
// 전역 변수를 사용하지 않고 스택 메모리로만 이용하여 구현해보기

// main
// - EnterLobby
// -- CreatePlayer
// -- EnterGame
// --- CreateMonsters
// --- EnterBattle

enum PlayerType {
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3
};

enum MonsterType {
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3
};

struct StatInfo {
    int hp = 0;
    int attack = 0;
    int defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
// StatInfo CreatePlayer2();
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
    srand((unsigned)time(nullptr));
    EnterLobby();
    return 0;
}

void EnterLobby() {
    while (true) {
        PrintMessage("로비에 입장했습니다.");

        // 플레이어 생성
        StatInfo playerInfo;
        CreatePlayer(&playerInfo);
        // StatInfo playerInfo = CreatePlayer2();

        PrintStatInfo("Player ", playerInfo);

        EnterGame(&playerInfo);
    }
}

void PrintMessage(const char* msg) {
    cout << "*****************************\n";
    cout << msg << '\n';
    cout << "*****************************\n";
}
void CreatePlayer(StatInfo* playerInfo) {
    bool ready = false;
    while (!ready) {
        PrintMessage("캐릭터 생성창");
        PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
        cout << "> ";

        int input;
        cin >> input;

        switch (input) {
        case PT_Knight:
            playerInfo->hp = 100;
            playerInfo->attack = 10;
            playerInfo->defence = 5;
            ready = true;
            break;
        case PT_Archer:
            playerInfo->hp = 80;
            playerInfo->attack = 15;
            playerInfo->defence = 3;
            ready = true;
            break;
        case PT_Mage:
            playerInfo->hp = 50;
            playerInfo->attack = 25;
            playerInfo->defence = 1;
            ready = true;
            break;
        }
    }
}

/*
StatInfo CreatePlayer2() {
    bool ready = false;
    StatInfo newPlayerInfo;
    while (!ready) {
        PrintMessage("캐릭터 생성창");
        PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
        cout << "> ";

        int input;
        cin >> input;

        switch (input) {
        case PT_Knight:
            newPlayerInfo.hp = 100;
            newPlayerInfo.attack = 10;
            newPlayerInfo.defence = 5;
            ready = true;
            break;
        case PT_Archer:
            newPlayerInfo.hp = 80;
            newPlayerInfo.attack = 15;
            newPlayerInfo.defence = 3;
            ready = true;
            break;
        case PT_Mage:
            newPlayerInfo.hp = 50;
            newPlayerInfo.attack = 25;
            newPlayerInfo.defence = 1;
            ready = true;
            break;
        }
    }

    return newPlayerInfo;
}
*/

void PrintStatInfo(const char* name, const StatInfo& info) {
    cout << "*****************************\n";
    cout << name << " : HP = " << info.hp << ", ATT = " << info.attack << ", DEF = " << info.defence << '\n';
    cout << "*****************************\n";
}

void EnterGame(StatInfo* playerInfo) {
    PrintMessage("게임에 입장했습니다.");

    const int MONSTER_COUNT = 2;

    while (true) {
        // 몬스터 생성. 배열로 2마리 정도
        StatInfo monsterInfo[MONSTER_COUNT];
        CreateMonsters(monsterInfo, MONSTER_COUNT);

        for (int i = 0; i < MONSTER_COUNT; i++)
            PrintStatInfo("Monster ", monsterInfo[i]);

        PrintStatInfo("Player ", *playerInfo);

        PrintMessage("[1] 전투 [2] 전투 [3] 도망");
        int input;
        cin >> input;

        if (input != 3) {
            bool victory = EnterBattle(playerInfo, &monsterInfo[input - 1]);
            if (!victory)
                break;
        }
            
    }
}

void CreateMonsters(StatInfo monsterInfo[], int count) {
    for (int i = 0; i < count; i++) {
        int randValue = (rand() % 3) + 1;

        switch (randValue) {
        case MT_Slime:
            monsterInfo[i].hp = 30;
            monsterInfo[i].attack = 5;
            monsterInfo[i].defence = 1;
            break;
        case MT_Orc:
            monsterInfo[i].hp = 40;
            monsterInfo[i].attack = 8;
            monsterInfo[i].defence = 2;
            break;
        case MT_Skeleton:
            monsterInfo[i].hp = 50;
            monsterInfo[i].attack = 15;
            monsterInfo[i].defence = 3;
            break;
        }
    }
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo) {
    while (true) {
        int damage = playerInfo->attack - monsterInfo->defence;
        if (damage < 0)
            damage = 0;

        monsterInfo->hp -= damage;
        if (monsterInfo->hp < 0)
            monsterInfo->hp = 0;

        PrintStatInfo("Monster ", *monsterInfo);

        if (monsterInfo->hp == 0) {
            PrintMessage("몬스터를 처치했습니다!");
            return true;
        }

        damage = monsterInfo->attack - playerInfo->defence;
        if (damage < 0)
            damage = 0;

        playerInfo->hp -= damage;
        if (playerInfo->hp < 0)
            playerInfo->hp = 0;

        PrintStatInfo("Player ", *playerInfo);

        if (playerInfo->hp == 0) {
            PrintMessage("사망 했습니다!");
            return false;
        }
    }
}
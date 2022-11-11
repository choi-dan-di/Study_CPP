#include <iostream>
using namespace std;

int main()
{
    int hp = 100;   // 몬스터 HP
    int damage = 100;   // 플레이어 데미지

    hp -= damage;   // 피격 판정
    bool isDead = (hp <= 0);    // 처치 판정

    // 몬스터가 죽었으면 경험치 추가
#pragma region if문    
    if (isDead)
        cout << "몬스터를 처치했습니다" << endl;
    /*
    else
        cout << "몬스터가 반격했습니다" << endl;
    */
    else
    {
        if (hp <= 20)
            cout << "몬스터가 도망가고 있습니다" << endl;
        else
            cout << "몬스터가 반격했습니다" << endl;
    }

    // if~else if~else 문
    /*
    if (isDead)
        cout << "몬스터를 처치했습니다" << endl;
    else if (hp <= 20)
        cout << "몬스터가 도망가고 있습니다" << endl;
    else
        cout << "몬스터가 반격했습니다" << endl;
    */

    /*
    // 보통 조건문이 하나인 경우에는 느낌표(!)만 사용해도 상관없지만 조건이 늘어나면 가독성이 좋지 않으므로 == false를 붙여주는 게 좋을 것 같다.
    if (!isDead)
        cout << "몬스터가 반격했습니다" << endl;

    // if (isDead == false)
    //    cout << "몬스터가 반격했습니다" << endl;
    */

    // 가위바위보 만들기
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;

    int input = ROCK;

    if (input == ROCK)
        cout << "바위를 냈습니다" << endl;
    else if (input == PAPER)
        cout << "보를 냈습니다" << endl;
    else if (input == SCISSORS)
        cout << "가위를 냈습니다" << endl;
    else
        cout << "뭘 낸겁니까?" << endl;
#pragma endregion

#pragma region switch-case문
    // if문과 동일하나 조건이 조금 더 많을 때 사용
    // 조건문엔 정수 계열만 넣을 수 있다.
    switch (input)
    {
        case ROCK:
            cout << "바위를 냈습니다" << endl;
            break;
        case PAPER:
            cout << "보를 냈습니다" << endl;
            break;
        case SCISSORS:
            cout << "가위를 냈습니다" << endl;
            break;
        default:
            cout << "뭘 낸겁니까?" << endl;
            break;
    }
#pragma endregion
}

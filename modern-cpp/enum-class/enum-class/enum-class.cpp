#include <iostream>
using namespace std;

// enum class

// 기존의 enum
// 따로 설정해주지 않으면 int 타입으로 잡히게 된다.
// unscoped enum (범위 없는)
enum PlayerType {
    // None,    // 중복 사용 불가
    PT_Knight,
    PT_Archer, 
    PT_Mage
};

enum MonsterType {
    // None,    // 중복 사용 불가
};

// enum class
enum class ObjectType : int {
    Player,
    Monster,
    Projectile
};

enum class ObjectType2 {
    Player,
    Monster,
    Projectile
};

int main()
{
    cout << sizeof(PlayerType) << endl;

    // enum class (scoped enum)
    // 1) 이름 공간 관리 (scoped)
    // 각 이름 객체 별 독립적으로 사용 가능

    // 2) 암묵적인 변환 금지
    double value = PT_Knight;
    // double value2 = ObjectType::Player;  // 사용 불가
    double value2 = static_cast<double>(ObjectType::Player);

    // 단점
    int choice;
    cin >> choice;

    // 코드가 길어질 수 있다.
    if (choice == static_cast<int>(ObjectType2::Monster)) {
        cout << "yyy" << endl;
    }

    unsigned int bitFlag;
    bitFlag = (1 << static_cast<int>(ObjectType::Player));

    return 0;
}
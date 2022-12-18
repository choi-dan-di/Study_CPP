#include <iostream>
using namespace std;

// override, final

class Creature {
public:
    virtual void Attack() {
        cout << "Creature!" << endl;
    }
};

class Player : public Creature {
public:
    virtual void Attack() override {
        cout << "Player!" << endl;
    }
};

class Knight : public Player {
public:
    // 재정의(override)
    /*
    virtual void Attack() const {
        cout << "Knight!" << endl;
        // const가 붙게되면 해당 함수 내에서 아무것도 수정할 수 없다. readonly
        // 그리고 const만 붙였을 경우 부모 클래스 Player 내의 Attack과 시그니처가 달라지기 때문에 제정의가 아닌
        // 새로운 함수가 생성되었다고 볼 수 있다.
        // _stamina = 10;   // 불가능
    }
    */

    // override를 붙여줌으로써 Player로부터 해당 함수를 상속 받아
    // 재정의 하고 있다는 사실을 알 수 있다.
    virtual void Attack() override {
        cout << "Knight!" << endl;
    }

    // final
    // 나를 끝으로 더이상 내 자식들에게 재정의를 허락하지 않는다는 의미이다.
    virtual void Attack() final {
        cout << "Knight!" << endl;
    }

private:
    int _stamina = 100;
};

int main()
{
    // Knight* knight = new Knight();
    Player* player = new Knight();

    // knight->Attack();
    player->Attack();

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// 람다(lambda)

// 함수 객체를 빠르게 만드는 문법

enum class ItemType {
    None,
    Armor,
    Weapon,
    Jewelry,
    Consumable
};

enum class Rarity {
    Common,
    Rare,
    Unique
};

class Item {
public:
    Item() { }
    Item(int itemId, Rarity rarity, ItemType type) 
        : _itemId(itemId), _rarity(rarity), _type(type) { }
public:
    int _itemId = 0;
    Rarity _rarity = Rarity::Common;
    ItemType _type = ItemType::None;
};

int main()
{
    vector<Item> v;
    v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
    v.push_back(Item(2, Rarity::Common, ItemType::Armor));
    v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
    v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

    // 람다 = 함수 객체를 손쉽게 만드는 문법
    // 람다 자체로 C++11에 '새로운' 기능이 들어간 것은 아니다.
    // 일종의 익명 함수(이름이 지어지지 않은 함수)
    {
        // Functor 이용
        struct IsUniqueItem {
            bool operator()(Item& item) {
                return item._rarity == Rarity::Unique;
            }
        };

        auto findIt = find_if(v.begin(), v.end(), IsUniqueItem());
        if (findIt != v.end())
            cout << "아이템 ID : " << findIt->_itemId << endl;

        // 람다 이용
        
        // 람다 표현식(lambda expression) : []() {}
        // auto isUniqueLambda = [](Item& item) -> int { return item._rarity == Rarity::Unique; };  // 반환 타입 추가
        // 클로저 (closure) = 람다에 의해 만들어진 실행 시점 객체
        auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; };
        auto findIt2 = find_if(v.begin(), v.end(), isUniqueLambda);
        if (findIt2 != v.end())
            cout << "아이템 ID : " << findIt2->_itemId << endl;
    }

    cout << "----------------------------------------\n";

    {
        // Functor 이용
        struct FindItemByItemId {
            FindItemByItemId(int itemId) : _itemId(itemId) { }

            bool operator()(Item& item) {
                return item._itemId == _itemId;
            }

            int _itemId;
        };

        int itemId = 4;
        auto findIt = find_if(v.begin(), v.end(), FindItemByItemId(itemId));
        if (findIt != v.end())
            cout << "아이템 ID : " << findIt->_itemId << endl;

        // 람다 이용
        // [] 캡처(capture) : 함수 객체 내부에 변수를 저장하는 개념과 유사하다.
        // 사진을 [캡처] 하듯, 일종의 스냅샷을 찍는다고 이해
        // 기본 캡처 모드 : 값(복사) 방식(=) / 참조 방식(&)
        auto findByItemIdLambda = [=](Item& item) { return item._itemId == itemId; };
        itemId = 10;    // 참조 방식이면 10으로 들어가고 값 방식이면 4가 들어간다.
        auto findIt2 = find_if(v.begin(), v.end(), findByItemIdLambda);
        if (findIt2 != v.end())
            cout << "아이템 ID : " << findIt2->_itemId << endl;

        // 복사 방식과 참조 방식의 차이점
        // 앞서 봐왔던 차이점과 크게 다를 것 없이 참조 방식은 원본의 주소를 가지게 된다.
    }

    cout << "----------------------------------------\n";

    {
        // Functor 이용
        struct FindItem {
            FindItem(int itemId, Rarity rarity, ItemType type) 
                : _itemId(itemId), _rarity(rarity), _type(type) { }

            bool operator()(Item& item) {
                return item._itemId == _itemId && item._rarity == _rarity && item._type == _type;
            }

            int _itemId;
            Rarity _rarity;
            ItemType _type;
        };

        int itemId = 4;
        Rarity rarity = Rarity::Unique;
        ItemType type = ItemType::Weapon;

        auto findIt = find_if(v.begin(), v.end(), FindItem(itemId, rarity, type));
        if (findIt != v.end()) {
            cout << "아이템 ID : " << findIt->_itemId << endl;
            cout << "희귀도 : " << static_cast<int>(findIt->_rarity) << endl;
            cout << "아이템 타입 : " << static_cast<int>(findIt->_type) << endl;
        }

        // 람다 이용
        
        // 변수마다 캡처 모드를 지정해서 사용 가능 : 값 방식(name), 참조 방식(&name)
        // [=, &type]
        // [&itemId, rarity, type]
        // 변수 하나하나 지정해주는 걸 더 선호한다.
        // -> 변수를 모두 묶어 같은 타입을 사용하는 것은 지양한다.
        auto findItemLambda = [=](Item& item) { 
            return item._itemId == itemId && item._rarity == rarity && item._type == type; 
        };
        auto findIt2 = find_if(v.begin(), v.end(), findItemLambda);
        if (findIt2 != v.end()) {
            cout << "아이템 ID : " << findIt2->_itemId << endl;
            cout << "희귀도 : " << static_cast<int>(findIt2->_rarity) << endl;
            cout << "아이템 타입 : " << static_cast<int>(findIt2->_type) << endl;
        }

        // 복사 방식과 참조 방식의 차이점
        // 앞서 봐왔던 차이점과 크게 다를 것 없이 참조 방식은 원본의 주소를 가지게 된다.
        // 동작은 완전 다르다.
    }

    cout << "----------------------------------------\n";

    {
        // 변수를 모두 복사 방식으로 사용했을 때의 발생할 수 있는 문제점
        // 클래스의 멤버 함수 내에서 람다를 이용한다음 외부에서 접근할 때 상태에 따라 메모리 오염이 발생할 수 있다.
        class Knight {
        public:
            auto ResetHpJob() {
                auto f = [this]() {
                    this->_hp = 200;
                };

                return f;
            }

        public:
            int _hp = 100;
        };

        class Functor {
        public:
            Functor(Knight* k) : _knight(k) { }

            void operator()() {
                _knight->_hp = 200;
            }

            Knight* _knight;
        };

        Knight* k = new Knight();
        auto job = k->ResetHpJob();
        delete k;
        job();
    }

    return 0;
}
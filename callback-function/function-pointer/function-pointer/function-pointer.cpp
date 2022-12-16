#include <iostream>
using namespace std;

// 함수 포인터 : 일반 함수 포인터

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

class Item
{
public:
    Item() : _itemId(0), _rarity(0), _ownerId(0)
    {

    }
public:
    int _itemId;    // 아이템을 구분하기 위한 ID
    int _rarity;    // 희귀도
    int _ownerId;   // 소지자 ID
};

// 사용하는 이유 : 여러 개의 조건을 통해 검색한다는 가정하에 한 번에 관리할 수 있다.
//Item* FindItemByItemId(Item items[], int itemCount, int itemId)
//{
//    for (int i = 0; i < itemCount; i++)
//    {
//        Item* item = &items[i];
//        if (item->_itemId = itemId)
//            return item;
//    }
//
//    return nullptr;
//}

typedef bool(ITEM_SELECTOR)(Item*, int);
// ITEM_SELECTOR* selector == bool(*selector)(Item*)
Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        // TODO 동작
        if (selector(item, value))
            return item;
    }

    return nullptr;
}

bool IsRareItem(Item* item, int value)
{
    return item->_rarity >= value;
}

bool IsOwnerItem(Item* item, int ownerId)
{
    return item->_ownerId == ownerId;
}

int main()
{
    int a = 10;

    // 1) 포인터       *
    // 2) 변수 이름    pointer
    // 3) 데이터 타입  int
    int* pointer = &a;

    // 함수
    typedef int(FUNC_TYPE)(int, int);
    // using FUNC_TYPE = int(int a, int b); // Modern C++에서 사용하는 문법

    // 1) 포인터       *
    // 2) 변수 이름    fn
    // 3) 데이터 타입  함수 (인자는 int, int / 반환은 int)
    FUNC_TYPE* fn;
    // 시그니처가 동일한 함수를 받을 수 있다.
    // 함수 포인터
    fn = Add;
    // fn = Sub;    // 사용하는 이유 : 이 부분만 바꿔주면 여러 줄의 코드를 한 번에 변경할 수 있다.

    // 함수의 이름은 함수의 시작 주소 (배열과 유사)
    // int result = Add(1, 2);
    int result = fn(1, 2);  // 기본 문법
    cout << result << endl;

    int result2 = (*fn)(1, 2);  // 함수 포인터는 *(접근 연산자)가 붙어도 함수 주소를 가리키는 것은 똑같다.
    cout << result2 << endl;

    int(*fn2)(int, int) = Add;
    int result3 = fn2(3, 5);
    cout << result3 << endl;

    Item items[10] = {};
    items[3]._rarity = 2;
    Item* rareItem = FindItem(items, 10, IsRareItem, 100);


    return 0;
}
#include <iostream>
using namespace std;

// 참조

struct StatInfo
{
	int hp;	// +0
	int attack;	// +4
	int defence;	// +8
};

// 1) 값 전달 방식
void PrintInfoByCopy(StatInfo info) {
	cout << "------------------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "------------------------------" << endl;
}

// 2) 주소 전달 방식
void PrintInfoByPtr(StatInfo* info) {
	cout << "------------------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "------------------------------" << endl;
}

// 3) 참조 전달 방식
void PrintInfoByRef(StatInfo& info) {
	cout << "------------------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "------------------------------" << endl;
}

// 참조 방식에 const를 붙이면 값 수정이 불가능하다.
// void PrintInfoByRef(const StatInfo& info)

// 포인터에도 const 사용이 가능하다. 위치에 따라 의미가 달라진다.
// void PrintInfoByPtr(const StatInfo* info)	// 앞에 붙였을 때
// void PrintInfoByPtr(StatInfo* const info)	// 뒤에 붙였을 때

void CreateMonster(StatInfo* info) {
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster() {
	// TODO : Heap 영역에서 뭔가를 찾아봄
	// 찾았으면
	// return monster~;

	return nullptr;
}

int main()
{
	// 1) 값 전달 방식
	int number = 1;
	// 2) 주소 전달 방식
	int* pointer = &number;
	*pointer = 2;

	// 3) 참조 전달 방식
	int& reference = number;
	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름을 지어준다는 의미
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(원본에다가) 그 값을 꺼내거나 넣으면 됨!
	reference = 3;	// number = 3;

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	// 사용 가능
	//StatInfo* pointer;
	// 가리키는 대상이 없을 때 nullptr 사용
	//StatInfo* pointer = nullptr;

	// 사용 불가능
	// StatInfo& reference2;
	// 참조 대상 무조건 지정 필요
	StatInfo& reference2 = info;

	// 포인터로 사용하던걸 참조로 넘겨주려면?
	// pointer[ 주소(&info) ]	ref, info[ 데이터 ]
	StatInfo* pointer2 = &info;
	StatInfo& ref = *pointer2;
	PrintInfoByRef(*pointer2);

	// 참조로 사용하던걸 포인터로 넘겨주려면?
	// pointer[ 주소 ]		reference2, info[ 데이터 ]
	StatInfo* ptr = &reference2;
	PrintInfoByPtr(&reference2);

	return 0;
}
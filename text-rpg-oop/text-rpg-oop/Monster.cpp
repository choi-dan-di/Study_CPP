#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "-------------------------\n";
	cout << "[몬스터 정보] HP : " << _hp << ", ATT : " << _attack << ", DEF : ", _defence << '\n';
	cout << "-------------------------\n";
}
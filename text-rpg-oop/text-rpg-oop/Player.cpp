#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "-------------------------\n";
	cout << "[플레이어 정보] HP : " << _hp << ", ATT : " << _attack << ", DEF : ", _defence << '\n';
	cout << "-------------------------\n";
}
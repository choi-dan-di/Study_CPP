#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "-------------------------\n";
	cout << "[�÷��̾� ����] HP : " << _hp << ", ATT : " << _attack << ", DEF : ", _defence << '\n';
	cout << "-------------------------\n";
}
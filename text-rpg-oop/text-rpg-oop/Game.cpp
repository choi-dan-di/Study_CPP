#include "Game.h"
#include "Player.h"
#include "Field.h"
#include <iostream>
using namespace std;

Game::Game() : _player(nullptr), _field(nullptr)
{

}

Game::~Game()
{
	if (_player != nullptr)
		delete _player;

	if (_field != nullptr)
		delete _field;
}

void Game::Init()
{
	_field = new Field();
}

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();

	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}

	_field->Update(_player);
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "-------------------------\n";
		cout << "ĳ���͸� �����ϼ���!\n";
		cout << "1) ��� 2) �ü� 3) ����\n";
		cout << "-------------------------\n";

		cout << "> ";

		int input = 0;
		cin >> input;

		if (input == PT_Knight)
			_player = new Knight();
		else if (input == PT_Archer)
			_player = new Archer();
		else if (input == PT_Mage)
			_player = new Mage();
	}
}
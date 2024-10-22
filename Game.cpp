#include "Game.h"

Game::Game()
{
	player1Field = nullptr;
	player2Field = nullptr;
}

Game::Game(const u_int& _fieldSize)
{
	player1Field = new Field(_fieldSize, 6);
	player2Field = new Field(_fieldSize, 6);
}

void Game::LaunchGame()
{
	while (!isGameEnded())
	{
		player1Field->DisplayField(player2Field);
		player2Field->DisplayField(player1Field);
	}
}

void Game::ShootOnField(Field*& _target, const u_int& _cordX, const u_int& _cordY)
{
	_target->SpaceHit(_cordX, _cordY);
}

void Game::RetrieveCordAndShoot(Field*& _target)
{
	u_int _cordX = 0;
	u_int _cordY = 0;
	bool _isCordValid = false;
	while (!_isCordValid)
	{
		DISPLAY("Enter X cord: ", false);
		cin >> _cordX;
		DISPLAY("Enter Y cord: ", false);
		cin >> _cordY;
		_isCordValid = _cordX >= 0 && _cordX < _target->GetFieldSize() && _cordY >= 0 && _cordY < _target->GetFieldSize();
	}
	ShootOnField(_target, _cordX, _cordY);
}



bool Game::isGameEnded()
{
	return player1Field->AreAllShipDead() || player2Field->AreAllShipDead();
}


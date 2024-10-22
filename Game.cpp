#include "Game.h"

Game::Game()
{
	player1Field = nullptr;
	player2Field = nullptr;
}

Game::Game(Field* _player1Field, Field* _player2Field)
{
	player1Field = _player1Field;
	player2Field = _player2Field;
}

void Game::LaunchGame()
{
	while (!isGameEnded())
	{
		player1Field->DisplayField(player2Field);
		player2Field->DisplayField(player1Field);
	}
}


bool Game::isGameEnded()
{
	return player1Field->AreAllShipDead() || player2Field->AreAllShipDead();
}


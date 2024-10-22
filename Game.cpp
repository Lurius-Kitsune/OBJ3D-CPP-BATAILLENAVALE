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
	do
	{

	} while (true);
}

bool Game::isGameEnded()
{
	return false;
}


#pragma once
#include "Player.h"
class Game
{
	Player* player1;
	Player* player2;

public:
	Game(const string& _namePlayer1, const string& _namePlayer2);
	~Game();
	void Launch();
};


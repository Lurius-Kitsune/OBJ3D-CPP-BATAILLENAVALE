#pragma once
#include "Field.h"
class Game
{
	Field* player1Field;
	Field* player2Field;

public:
	Game();
	Game(const u_int& _fieldSize);
public:
	void LaunchGame();
	void ShootOnField(Field*& _target, const u_int& _cordX, const u_int& _cordY);
	void RetrieveCordAndShoot(Field*& _target);
private:
	bool isGameEnded();
};


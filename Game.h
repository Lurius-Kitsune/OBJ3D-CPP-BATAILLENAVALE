#pragma once
#include "Field.h"
class Game
{
	Field* player1Field;
	Field* player2Field;
	bool _isGameEnded;

public:
	Game();
	Game(Field* _player1Field, Field* _player2Field);
public:
private:
};


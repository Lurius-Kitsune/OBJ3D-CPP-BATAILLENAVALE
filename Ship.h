#pragma once
#include <iostream>
#include <string>
#include "Macro.h"     

using namespace std;

typedef unsigned int u_int;

class Ship
{
	string name;
	u_int spaceSize;
	u_int damageTaken;
	bool isDead;

public:
	u_int GetSpaceSize();

	Ship();

	Ship(const string& _name, const int _spaceSize);
public:
	bool IsAlive();
	void TakeADamage();
private:
};


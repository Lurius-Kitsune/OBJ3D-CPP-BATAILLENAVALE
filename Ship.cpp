#include "Ship.h"

u_int Ship::GetSpaceSize()
{
	return spaceSize;
}

Ship::Ship()
{
	name = "Unknown";
	spaceSize = 0;
	damageTaken = 0;
	isDead = true;
}

Ship::Ship(const string& _name, const int _spaceSize)
{
	name = _name;
	spaceSize = _spaceSize;
	damageTaken = 0;
	isDead = 0;
}

bool Ship::IsAlive()
{
	return false;
}

void Ship::TakeADamage()
{
}



#pragma once
#include "Cordinates.h"
#include "Ship.h"

class Tile
{
	Cordinates cordinates;
	Ship* ship;
	bool isHit;

public:
	Tile() = default;
	Tile(const Cordinates& _cordinates);
public:
	void AddShip(Ship* _ship);
	bool IsHit(const Cordinates& _attackLocation, bool& _isSunk);
	void Display();
};



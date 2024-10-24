#pragma once
#include "Cordinates.h"
#include "Ship.h"

class Tile
{
	Cordinates cordinates;
	Ship* ship;
	bool isHit;
	bool isOpponent;

public:

	void SetIsHit(const bool _hasHit)
	{
		isHit = _hasHit;
	}

	void SetIsOpponent(const bool _hisOpponent)
	{
		isOpponent = _hisOpponent;
	}

	bool IsOpponent()const
	{
		return isOpponent;
	}

	Ship* GetShip()
	{
		return ship;
	}

	void SetShip(Ship* _ship)
	{
		ship = _ship;
	}

	bool IsAvailable()const
	{
		return !ship;
	}

	Tile() = default;
	Tile(const Cordinates& _cordinates, const bool _isOpponent);
public:
	bool IsHit();
	void Display();
};



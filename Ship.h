#pragma once
#include "Cordinates.h"

class Grid;

class Ship
{
	char appearance;
	u_int size;
	Cordinates* cordinatesArray;
	u_int hitsCount;

public:
	char GetAppearance() const
	{
		return appearance;
	}

	u_int GetHitPartCount() const
	{
		return hitsCount;
	}

	Ship(const char _appearance, const u_int& _size);
	~Ship();

public:
	bool AddHit();
	void Setup(const Grid& _grid);
	bool IsHit(const Cordinates& _attackLocation);

private:
};


#pragma once
#include "Cordinates.h"

class Grid;

enum DirectionType
{
	DT_RIGHT,
	DT_LEFT,
	DT_DOWN,
	DT_UP,
	
	DT_COUNT
};

class Ship
{
	char appearance;
	u_int size;
	Cordinates** cordinatesArray;
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

	Ship() = default;
	Ship(const char _appearance, const u_int& _size);
	Ship(Ship* _ship);
	~Ship();

public:
	bool AddHit();
	void Setup(const Grid& _grid, const u_int& _tryCount);
	bool IsHit(const Cordinates* _attackLocation);

private:
	bool CheckCords(Cordinates* _cords, const Grid& _grid, const u_int& _index);
	bool CheckStartCords(Cordinates*& _cords, const Grid& _grid, const u_int _index);
	bool CheckNextCords(Cordinates* _startCords, const Grid& _grid, const u_int _index, const DirectionType& _direction);
	Cordinates* ComputeNextCords(const Cordinates* _startCords, const u_int _index, const DirectionType& _direction);
};


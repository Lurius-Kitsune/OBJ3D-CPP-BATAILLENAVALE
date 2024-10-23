#pragma once
#include "Tile.h";
class Grid
{
	Tile** grid;
	u_int gridSize;

public:

	u_int GetGridSize() const
	{
		return gridSize;
	}

	Grid(const u_int _gridSize);
	~Grid();

public:
	void Init();
	bool CheckAttack(const Cordinates& _cordinate);
};


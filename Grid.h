#pragma once
#include "Tile.h";
class Grid
{
	Tile** grid;
	u_int gridSize;

public:

	Tile* GetTile(const Cordinates& _cordinate) const
	{
		if (_cordinate.y >= gridSize || _cordinate.x >= gridSize) return nullptr;
		return &grid[_cordinate.x][_cordinate.y];
	}

	u_int GetGridSize() const
	{
		return gridSize;
	}

	Grid(const u_int _gridSize);
	~Grid();

public:
	void Init();
	void Display();
	bool CheckAttack(const Cordinates& _cordinate);
};


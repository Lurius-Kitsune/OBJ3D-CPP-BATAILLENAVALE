#pragma once
#include "Tile.h";
class Grid
{
	Tile** grid;
	u_int gridSize;

public:

	void SetTile(const Cordinates& _cordinate, Tile _tile) const
	{
		grid[_cordinate.x][_cordinate.y] = _tile;
	}

	Tile* GetTile(const Cordinates* _cordinate) const
	{
		if (_cordinate->y >= gridSize || _cordinate->x >= gridSize) return nullptr;
		return &grid[_cordinate->x][_cordinate->y];
	}

	u_int GetGridSize() const
	{
		return gridSize;
	}

	Grid() = default;
	Grid(const u_int _gridSize);
	~Grid();

public:
	void Init(const bool _isOpponent);
	void Display();
	Tile* CheckAttack(const Cordinates* _cordinate);
};


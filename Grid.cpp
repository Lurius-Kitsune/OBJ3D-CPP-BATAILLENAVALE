#include "Grid.h"

Grid::Grid(const u_int _gridSize)
{
	gridSize = _gridSize;
	grid = new Tile*[gridSize];
	// On peut initialiser ici mais cest mauvais ( on sera en 2 eme année
}

Grid::~Grid()
{
	delete[] grid;
}

void Grid::Init(const bool _isOpponent)
{
	for (u_int  _rowIndex = 0; _rowIndex < gridSize; _rowIndex++)
	{
		grid[_rowIndex] = new Tile[gridSize];
		for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
		{
			grid[_rowIndex][_columnIndex] = Tile({ _rowIndex, _columnIndex }, _isOpponent);
		}
	}
}

void Grid::Display()
{
	DISPLAY(" ", false);
	for (u_int _index = 0; _index < gridSize; _index++)
	{
		DISPLAY(" ", false);
		DISPLAY(to_string(_index+1), false);
	}

	DISPLAY("", true);
	for (u_int _rowIndex = 0; _rowIndex < gridSize; _rowIndex++)
	{
		DISPLAY(char('A' + _rowIndex), false);
		for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
		{
			DISPLAY(" ", false);
			grid[_rowIndex][_columnIndex].Display();
		}
		DISPLAY(" ", false);
		DISPLAY(char('A' + _rowIndex), true);
	}
	DISPLAY(" ", false);
	for (u_int _index = 0; _index < gridSize; _index++)
	{
		DISPLAY(" ", false);
		DISPLAY(to_string(_index + 1), false);
	}
	DISPLAY(" ", true);
}

Tile* Grid::CheckAttack(const Cordinates* _cordinate)
{
	bool _isSunk = false;
	Tile& _tile = grid[_cordinate->x][_cordinate->y];
	const bool _hasHit = _tile.IsHit(_isSunk);
	
	if (!_hasHit)
	{
		DISPLAY("LOUPER !", true);
		return nullptr;
	}

	string _sunkText = _isSunk ? "et coulé " : " ";
	DISPLAY("Touché " + _sunkText + "à : " + _cordinate->ToString() + " !", true);
	return &_tile;

}

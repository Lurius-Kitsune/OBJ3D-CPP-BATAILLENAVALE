#include "Grid.h"

Grid::Grid(const u_int _gridSize)
{
	gridSize = _gridSize;
	grid = new Tile*[gridSize];
	// On peut initialiser ici mais cest mauvais ( on sera en 2 eme ann�e
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
	const string& _color = grid[0][0].IsOpponent() ? RED : GREEN;
	DISPLAY(" ", false);
	for (u_int _index = 0; _index < gridSize; _index++)
	{
		DISPLAY(" ", false);
		DISPLAY(_color + to_string(_index+1) + RESET, false);
	}

	DISPLAY("", true);
	for (u_int _rowIndex = 0; _rowIndex < gridSize; _rowIndex++)
	{
		DISPLAY(_color, false);
		DISPLAY( char('A' + _rowIndex), false);
		DISPLAY(RESET, false);

		for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
		{
			DISPLAY(" ", false);
			grid[_rowIndex][_columnIndex].Display();
		}
		DISPLAY("", true);
	}
	DISPLAY(" ", true);
}

Tile* Grid::CheckAttack(const Cordinates* _cordinate)
{
	Tile& _tile = grid[_cordinate->x][_cordinate->y];
	const bool _hasHit = _tile.IsHit();
	
	if (!_hasHit)
	{
		DISPLAY("LOUPER !", true);
		return nullptr;
	}

	string _sunkText = _tile.GetShip()->IsSunk() ? "et coul� " : " ";
	DISPLAY("Touch� " + _sunkText + "� : " + _cordinate->ToString() + " !", true);
	return &_tile;

}

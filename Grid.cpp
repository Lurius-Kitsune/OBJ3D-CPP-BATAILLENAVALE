#include "Grid.h"

Grid::Grid(const u_int _gridSize)
{
	gridSize = _gridSize;
	grid = nullptr;
	// On peut initialiser ici mais cest mauvais ( on sera en 2 eme année
}

Grid::~Grid()
{
	delete[] grid;
}

void Grid::Init()
{
	for (u_int  _rowIndex = 0; _rowIndex < gridSize; _rowIndex++)
	{
		grid[_rowIndex] = new Tile[gridSize];
		for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
		{
			grid[_rowIndex][_columnIndex] = Tile({ _rowIndex, _columnIndex });
		}
	}
}

bool Grid::CheckAttack(const Cordinates& _cordinate)
{
	for (u_int _rowIndex = 0; _rowIndex < gridSize; _rowIndex++)
	{
		for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
		{
			bool _isSunk;
			if (grid[_rowIndex][_columnIndex].IsHit(_cordinate, _isSunk))
			{
				string _sunkText = _isSunk ? "et coulé " : " ";
				DISPLAY("Touché " + _sunkText + "à : " + _cordinate.ToString() + " !", true);
				return true;
			}
		}
	}
	return false;
}

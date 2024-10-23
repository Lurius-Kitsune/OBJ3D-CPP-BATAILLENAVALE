#include "Ship.h"
#include "Grid.h"

Ship::Ship(const char _appearance, const u_int& _size)
{
	appearance = _appearance;
	size = _size;
	cordinatesArray = nullptr;
	hitsCount = 0;
}

Ship::~Ship()
{
	delete[] cordinatesArray;
}

bool Ship::AddHit()
{
	hitsCount++;
	return hitsCount >= size;
}

void Ship::Setup(const Grid& _grid)
{
	do
	{
		const Cordinates& _startCoords = Cordinates::GetRandom(1, _grid.GetGridSize());

		if (!_grid.GetTile().IsAvailableAtCords(_startCoords)) continue;

		// tester s'il la case est libre 

		// placer à droite
		for (u_int _index = 0; _index < size-1; _index++)
		{
			const Cordinates& _nextCords = { _startCoords.x + _index, _startCoords.y };
			if (!_grid.GetTile().IsAvailableAtCords(_nextCords)) break;
			cordinatesArray[_index + 1] = _nextCords;
			if (_index == size - 2)
			{
				//TODO func
				//cordinatesArray[]
				return;
			}
		}

		// placer à gauche
		for (u_int _index = 0; _index < size - 1; _index++)
		{
			const Cordinates& _nextCords = { _startCoords.x - _index, _startCoords.y };
			if (!_grid.GetTile().IsAvailableAtCords(_nextCords)) break;
		}

		// placer à en bas
		for (u_int _index = 0; _index < size - 1; _index++)
		{
			const Cordinates& _nextCords = { _startCoords.x , _startCoords.y + _index };
			if (!_grid.GetTile().IsAvailableAtCords(_nextCords)) break;
		}

		// placer en haut
		for (u_int _index = 0; _index < size - 1; _index++)
		{
			const Cordinates& _nextCords = { _startCoords.x, _startCoords.y - _index };
			if (!_grid.GetTile().IsAvailableAtCords(_nextCords)) break;
		}
	} while (true);
}

bool Ship::IsHit(const Cordinates& _attackLocation)
{

	for (u_int _index = 0; _index < size; _index++)
	{
		if (cordinatesArray[_index].IsSame(_attackLocation)) return true;
	}

	return false;
}

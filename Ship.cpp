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
		const Cordinates& _cordinates = Cordinates::GetRandom(1, _grid.GetGridSize());
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

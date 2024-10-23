#include "Ship.h"
#include "Grid.h"

Ship::Ship(const char _appearance, const u_int& _size)
{
	appearance = _appearance;
	size = _size;
	cordinatesArray = new Cordinates[size];
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
	Cordinates _startCords;

	const u_int& _startDirectionIndex = GetRandomNumberInRange(DT_COUNT);

	bool _isSet = false;
	do
	{
		// Je cherche à établir une nouvelle cordonnée
		if (!CheckStartCords(_startCords ,_grid, 0)) continue;

		// tester s'il la case est libre 
		// Pour chaque direction
		for (u_int _directionIndex = _startDirectionIndex; !_isSet && _directionIndex < DT_COUNT + _startDirectionIndex; _directionIndex++)
		{
			const u_int& _finalDirection = _directionIndex > DT_COUNT ? 0 : _directionIndex;
			bool _isValidDirection = true;

			// Pour toute la taille du bateau
			for (u_int _index = 0; _index < size - 1; _index++)
			{
				if (!CheckNextCords(_startCords, _grid, _index + 1, DirectionType(_finalDirection)))
				{
					_isValidDirection = false;
					continue;
				}

				// Si le bateau est entiérement posé alors on quitte !
				if (_index == size - 2)
				{
					_isSet = true;
					break;
				}
			}
		}
	} while (!_isSet);

	// J'ajoute le bateau aux case qui contienne les cordonnée !
	for (size_t _index = 0; _index < size; _index++)
	{
		_grid.GetTile(cordinatesArray[_index])->AddShip(this);
	}
}

bool Ship::IsHit(const Cordinates& _attackLocation)
{

	for (u_int _index = 0; _index < size; _index++)
	{
		if (cordinatesArray[_index].IsSame(_attackLocation)) return true;
	}

	return false;
}

bool Ship::CheckCords(const Cordinates& _cords, const Grid& _grid, const u_int& _index)
{
	Tile* _tile = _grid.GetTile(_cords);
	if (!_tile || !_tile->IsAvailable()) return false;

	cordinatesArray[_index] = _cords;

	return true;
}

bool Ship::CheckStartCords(Cordinates& _cords, const Grid& _grid, const u_int _index)
{
	// On génére une nouvelle cordonner
	_cords = Cordinates::GetRandom(_grid.GetGridSize(), 1);
	return CheckCords(_cords, _grid, _index);
}

bool Ship::CheckNextCords(const Cordinates& _startCords, const Grid& _grid, const u_int _index, const DirectionType& _direction)
{
	// On génére une nouvelle cordonner
	const Cordinates _cords = ComputeNextCords(_startCords, _index, _direction);

	return CheckCords(_cords, _grid, _index);
}

Cordinates Ship::ComputeNextCords(const Cordinates& _startCords, const u_int _index, const DirectionType& _direction)
{
	switch (_direction)
	{
	case DT_RIGHT:
		return Cordinates( _startCords.x + _index, _startCords.y );
	case DT_LEFT:
		return Cordinates(_startCords.x - _index, _startCords.y);
	case DT_UP:
		return Cordinates(_startCords.x , _startCords.y - _index);
	case DT_DOWN:
		return Cordinates(_startCords.x , _startCords.y + _index);
	default:
		break;
	}
}

#include "Field.h"

Space** Field::GetSpaces() const
{
	return spaces;
}

u_int Field::GetFieldSize() const
{
	return fieldSize;
}

Field::Field()
{
	spaces = nullptr;
	fieldSize = 0;
	maxShip = 0;
}

Field::Field(const u_int _fieldSize, const u_int _maxShip)
{
	fieldSize = _fieldSize;
	spaces = new Space*[fieldSize];

	for (u_int _x = 0; _x < fieldSize; _x++)
	{
		spaces[_x] = new Space[fieldSize];
		for (u_int _y = 0; _y < fieldSize; _y++)
		{
			spaces[_x][_y] = Space();
		}
	}

	maxShip = _maxShip;
}

void Field::DisplayField()
{
	for (u_int _i = 0; _i < fieldSize; _i++)
	{
		DISPLAY("\t" + to_string(_i + 1), false);
	}
	DISPLAY("", true);
	for (u_int _x = 0; _x < fieldSize; _x++)
	{
		DISPLAY(static_cast<char>(_x + 65), false);
		for (u_int _y = 0; _y < fieldSize; _y++)
		{
			Space _actualSpace = spaces[_x][_y];
			const string _displayChar = (_actualSpace.isShipOnIt() ? _actualSpace.GetIsTouched() ? "X" : "+" : "-");
			DISPLAY("\t" + _displayChar, false);
		}
		DISPLAY("", true);
	}
}

void Field::DisplayField(Field* _target)
{
	for (u_int _i = 0; _i < fieldSize; _i++)
	{
		DISPLAY("\t" + to_string(_i + 1), false);
	}
	DISPLAY("", true);
	for (u_int _x = 0; _x < fieldSize; _x++)
	{
		DISPLAY(static_cast<char>(_x + 65), false);
		for (u_int _y = 0; _y < fieldSize; _y++)
		{
			Space _actualSpace = _target->GetSpaces()[_x][_y];
			const string _displayChar = (_actualSpace.GetIsTouched() ? _actualSpace.isShipOnIt() ? "X" : "O" : "-");
			DISPLAY("\t" + _displayChar, false);
		}
		DISPLAY("", true);
	}
}

void Field::PlaceShip(const bool _isVertical, Ship*& _ship, const u_int& _cordX, const u_int& _cordY)
{
	// Je pose mon ancre sois sur une ligne sois sur une colonne
	// Si c'est vertical -> on garde la colonne et ont prend en point de d�part la ligne (X)
	// Sinon on garde la ligne et on prend la colonne (Y)
	u_int _startCordinate = _isVertical ? _cordX : _cordY;
	if (isOutOfBond(_ship,  _startCordinate)) return; // OutOfBound detected !

	// TODO a optimiser !
	u_int _revertIndex = -1;
	if (!_isVertical)
	{
		for (u_int _i = _startCordinate; _i < _ship->GetSpaceSize() + _startCordinate; _i++)
		{
			if (isShipOnItAround(_cordX, _i, _ship))
			{
				_revertIndex = _i;
				break;
			}
			spaces[_cordX][_i].SetProperty(_ship);
		}
		if (_revertIndex != -1)
		{
			for (u_int _i = _revertIndex; _i > _startCordinate; _i--)
			{
				spaces[_cordX][_i].SetProperty(nullptr);
			}
		}
	}
	else
	{
		for (u_int _i = _startCordinate; _i < _ship->GetSpaceSize() + _startCordinate; _i++)
		{
			if (isShipOnItAround(_i, _cordY, _ship))
			{
				_revertIndex = _i;
				break;
			}
			spaces[_i][_cordY].SetProperty(_ship);
		}
		if (_revertIndex != -1)
		{
			for (u_int _i = _revertIndex; _i > _startCordinate; _i--)
			{
				spaces[_i][_cordY].SetProperty(nullptr);
			}
		}
	}
}

void Field::SpaceHit(const u_int& _x, const u_int& _y)
{
	if (spaces[_x][_y].GetIsTouched()) return;

	if (spaces[_x][_y].isShipOnIt())
	{
		DISPLAY("TOUCHER", true);
		spaces[_x][_y].GetProperty()->TakeADamage();
	}
	spaces[_x][_y].SetIsTouched(true);
}

bool Field::AreAllShipDead() const
{
	for (u_int _x = 0; _x < fieldSize; _x++)
	{
		for (u_int _y = 0; _y < fieldSize; _y++)
		{
			if (spaces[_x][_y].isShipOnIt() && !spaces[_x][_y].GetProperty()->IsDead())
			{
				return false;
			}
		}
	}
	return true;
}

bool Field::isOutOfBond(Ship*& _ship, const u_int _cord) const
{
	return _cord + _ship->GetSpaceSize() >= fieldSize || _cord < 0;
}

// Retourne vrai si un bateau est autour de la case est que ce n'est pas lui meme
bool Field::isShipOnItAround(const int _cordX, const int _cordY, Ship*& _ship) const
{
	

	// Case de gauche
	if (_cordX - 1 >= 0 && spaces[_cordX - 1][_cordY].isShipOnIt() && spaces[_cordX - 1][_cordY].GetProperty() != _ship) return true;

	// Case de droite
	if (_cordX + 1 < fieldSize && spaces[_cordX + 1][_cordY].isShipOnIt() && spaces[_cordX + 1][_cordY].GetProperty() != _ship) return true;

	// Case du haut
	if (_cordY - 1 >= 0 && spaces[_cordX][_cordY - 1].isShipOnIt() && spaces[_cordX][_cordY - 1].GetProperty() != _ship) return true;

	// Case du bas
	if (_cordY + 1 < fieldSize && spaces[_cordX][_cordY + 1].isShipOnIt() && spaces[_cordX][_cordY + 1].GetProperty() != _ship) return true;

	return false;

}

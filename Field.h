#pragma once
#include "Space.h"
class Field
{
	Space** spaces;
	u_int fieldSize;
	u_int maxShip;

public:
	Space** GetSpaces()const;
	u_int GetFieldSize()const;
	Field();
	Field(const u_int _fieldSize, const u_int _maxShip);
public:
	void DisplayField();
	void DisplayField(Field* _target);
	void PlaceShip(const bool _isVertical, Ship*& _ship, const u_int& _cordX, const u_int& _cordY);
	void SpaceHit(const u_int& _x, const u_int& _y);
	bool AreAllShipDead()const;
private:
	bool isOutOfBond(Ship*& _ship, const u_int _cord) const;
	bool isShipOnItAround(const int _cordX, const int _cordY, Ship*& _ship) const;
};


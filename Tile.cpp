#include "Tile.h"


Tile::Tile(const Cordinates& _cordinates)
{
	cordinates = _cordinates;
	ship = nullptr;
	isHit = false;
}


bool Tile::IsHit(bool& _isSunk)
{
	isHit = true;

	if (ship)
	{
		_isSunk = ship->AddHit();
	}

	return ship;
}


void Tile::Display()
{
	// Mettre en rouge si c'est toucher !
	// bleu si c'est de l'eau
	// sinon blanc
	const string& _color = isHit ? ship ? RED : BLUE : WHITE;
	const char _char = !ship ? '~' : ship->GetAppearance();
	DISPLAY(_color + _char , false);
	//DISPLAY("~", false);
}

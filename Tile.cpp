#include "Tile.h"



Tile::Tile(const Cordinates& _cordinates, const bool _isOpponent)
{
	cordinates = _cordinates;
	ship = nullptr;
	isHit = false;
	isOpponent = _isOpponent;
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
	const string& _color = isHit ? ship ? ship->IsSunk() ? RED BLINK_TEXT : YELLOW BLINK_TEXT : BLUE: WHITE;
	const char _char = ship ? (isOpponent && !ship->IsSunk() ? '#' : ship->GetAppearance()) : '~';
	DISPLAY(_color + _char , false);
	DISPLAY(RESET_BLINK RESET, false);
	//DISPLAY("~", false);
}

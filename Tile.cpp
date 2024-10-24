#include "Tile.h"



Tile::Tile(const Cordinates& _cordinates, const bool _isOpponent)
{
	cordinates = _cordinates;
	ship = nullptr;
	isHit = false;
	isOpponent = _isOpponent;
}

bool Tile::IsHit()
{
	isHit = true;

	if (ship)
	{
		ship->AddHit();
	}

	return ship;
}


void Tile::Display()
{
	/*
	* Code couleur
	* Rouge -> Bateau couler
	* Jaune -> Toucher
	* Bleu -> toucher vide
	* Blanc -> case non toucher
	*/

	string _color;

	if (isOpponent)
	{
		_color = ship ? (isHit ? (ship->IsSunk() ? RED BLINK_TEXT : YELLOW) : RESET) : (isHit ? BLUE : CYAN);
	}
	else
	{
		_color = ship ? (isHit ? (ship->IsSunk() ? RED BLINK_TEXT : YELLOW) : RESET) : (isHit ? BLUE : CYAN);
	}

	const char _char = ship ? (isOpponent && !ship->IsSunk() ? '#' : ship->GetAppearance()) : '~';
	DISPLAY(_color + _char , false);
	DISPLAY(RESET_BLINK RESET, false);
	//DISPLAY("~", false);
}

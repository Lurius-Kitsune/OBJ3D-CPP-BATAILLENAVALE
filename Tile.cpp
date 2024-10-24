#include "Tile.h"


Tile::Tile(const Cordinates& _cordinates)
{
	cordinates = _cordinates;
	ship = nullptr;
	isHit = false;
}


bool Tile::IsHit(const Cordinates* _attackLocation, bool& _isSunk)
{
	
	isHit = cordinates.IsSame(_attackLocation);
	
	if (ship && isHit)
	{
		_isSunk = ship->AddHit();
	}

	return ship && isHit;
}


void Tile::Display()
{
	// Mettre en rouge si c'est toucher !
	// bleu si c'est de l'eau
	// sinon blanc
	DISPLAY((!ship ? !isHit ? '~' : 'O' : ship->GetAppearance()), false);
	//DISPLAY(RESET, false);
}

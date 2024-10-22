#include "Space.h"

void Space::SetProperty(Ship* _property)
{
	spaceProperty = _property;
}

Ship* Space::GetProperty() const
{
	return spaceProperty;
}

bool Space::GetIsTouched() const
{
	return isTouched;
}

Space::Space()
{
	spaceProperty = nullptr;
	isTouched = false;
}

bool Space::isShipOnIt()
{
	return GetProperty();
}




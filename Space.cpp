#include "Space.h"

void Space::SetProperty(Ship* _property)
{
	spaceProperty = _property;
}

Ship* Space::GetProperty() const
{
	return spaceProperty;
}

void Space::SetIsTouched(const bool _set)
{
	isTouched = _set;
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




#pragma once
#include "Ship.h"
class Space
{
	Ship* spaceProperty;
	bool isTouched;

public:
	void SetProperty(Ship* _property);
	Ship* GetProperty() const;
	bool GetIsTouched()const;

	Space();

public:
	bool isShipOnIt();
private:

};


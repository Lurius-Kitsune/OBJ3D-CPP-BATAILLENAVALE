#pragma once
#include "Ship.h"
class Space
{
	Ship* spaceProperty;
	bool isTouched;

public:
	void SetProperty(Ship* _property);
	Ship* GetProperty() const;
	void SetIsTouched(const bool _set);
	bool GetIsTouched()const;

	Space();

public:
	bool isShipOnIt();
private:

};


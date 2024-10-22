#pragma once
#include "Macro.h"


bool IsUpper(const char _char)
{
	int _charInInt = static_cast<int>(_char);
	return _charInInt >= 65 && _charInInt <= 90;
}

bool IsLower(const char _char)
{
	int _charInInt = static_cast<int>(_char);
	return _charInInt >= 97 && _charInInt <= 122;
}
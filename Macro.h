// File Macro.h
#pragma once
#include <iostream>
#include <string>
#include "MacroConsole.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define CLEAR cin.clear(); \
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

#define DISPLAY(_value, _makeEndl) cout << _value; \
                                   if (_makeEndl) cout << endl;

#define CLEAR_SCREEN system("cls");
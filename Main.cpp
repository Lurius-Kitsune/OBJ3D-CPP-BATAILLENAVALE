// File : Main.cpp
#include "Main.h"

#pragma region Struct
#pragma endregion

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

    locale::global(locale("fr-FR")); // UTF8

    Field* _fieldTest = new Field(10,10);
    Ship* _ship = new Ship("Porte-Avion", 5);
    _fieldTest->PlaceShip(false, _ship, 0, 0);
    _fieldTest->DisplayField();
    delete _ship;
    delete _fieldTest;
}
// File : Main.cpp
#include "Main.h"

#pragma region Struct
#pragma endregion

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

    locale::global(locale("fr-FR")); // UTF8
	Game* game = new Game(10);
	game->LaunchGame();


    delete _ship;
    delete _fieldTest;
}
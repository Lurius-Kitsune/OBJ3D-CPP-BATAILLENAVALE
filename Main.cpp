#include "Macro.h"
#include "Grid.h"
// Les classe � cr�e 
// Ship
    // Grid
    // Position
    // Player
    // Game
    // Marker
    // Missile
    // Tile

// feature
// Menu d�roulant d�but du jeu - Game
// D�finition de la grille - Grid
//Etablissement des bateaux sur la grille - Grid
// Systeme de jeu tour par tour - Game
// Menu s�lection joueurs - Game
// 
// Choix de la position du tir - Player qui attaque
// Systeme de marquage - Marker
// System toucher couler - Player qui se fait attaquer
// D�terminer la fin de la partie - Game

// Game -> 2 joueur -> Grille -> Case -> Bateau ou marqueur -> Position

int main()
{
    Grid _grid = Grid(10);
    _grid.Init();

    Ship _ship[] =
    {
        Ship('1', 5),
        Ship('2', 4),
        Ship('3', 3),
        Ship('4', 3),
        Ship('5', 2),
    };

    return EXIT_SUCCESS;
}

#include "Macro.h"
#include "Grid.h"
// Les classe à crée 
// Ship
    // Grid
    // Position
    // Player
    // Game
    // Marker
    // Missile
    // Tile

// feature
// Menu déroulant début du jeu - Game
// Définition de la grille - Grid
//Etablissement des bateaux sur la grille - Grid
// Systeme de jeu tour par tour - Game
// Menu sélection joueurs - Game
// 
// Choix de la position du tir - Player qui attaque
// Systeme de marquage - Marker
// System toucher couler - Player qui se fait attaquer
// Déterminer la fin de la partie - Game

// Game -> 2 joueur -> Grille -> Case -> Bateau ou marqueur -> Position

int main()
{
    Grid _grid = Grid(10);
    _grid.Init();

    enum ShipType
    {
        PATROLER = 2,
        SUBMARINE = 3,
        DESTROYER = 3,
        CRUISER = 4,
        AIRCRAFT_CARRIER = 5,

        ST_COUNT
    };

    struct ShipData
    {
        u_int count;
        Ship ship;
    };

    ShipData _shipData[] =
    {
        { 1, Ship('1', AIRCRAFT_CARRIER) },
        { 1, Ship('2', CRUISER)},
        { 1, Ship('3', DESTROYER)},
        { 1, Ship('4', SUBMARINE)},
        { 1, Ship('5', PATROLER)},
    };

    // Pour chaque type de bateau
    for (u_int _index = 0; _index < size(_shipData); _index++)
    {
        // Pour chaque meme type de bateau
        for (u_int _shipIndex = 0; _shipIndex < _shipData[_index].count; _shipIndex++)
        {
            // Je place un bateau sur la grille
            _shipData[_index].ship.Setup(_grid);
        }
    }
    

    return EXIT_SUCCESS;
}

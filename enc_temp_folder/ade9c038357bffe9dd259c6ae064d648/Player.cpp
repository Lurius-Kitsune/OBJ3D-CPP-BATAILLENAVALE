#include "Player.h"

Player::Player(const string& _name, const u_int& _gridSize,
    ShipData* _shipData, const u_int& _shipDataCount)
{
    name = _name;
    ownGrid = Grid(_gridSize);
    opponentGrid = Grid(_gridSize);
    shipData = _shipData;
    shipDataCount = _shipDataCount;
}

void Player::Init()
{
    ownGrid.Init();
    opponentGrid.Init();

    // Pour chaque type de bateau
    for (u_int _index = 0; _index < shipDataCount; _index++)
    {
        // Pour chaque meme type de bateau
        for (u_int _shipIndex = 0; _shipIndex < shipData[_index].count; _shipIndex++)
        {
            // Je place un bateau sur la grille
            shipData[_index].ship.Setup(ownGrid, 10);
        }
    }
}

Cordinates Player::GetCoordsToAttack()
{
    u_int _posX, _posY;

    DISPLAY("Tu veux attaquer ou?", true);
    cin >> _posX;
    cin >> _posY;
    return { _posX, _posY };
}

bool Player::Attack(const Cordinates& _coordsToAttack)
{
    return ownGrid.CheckAttack(_coordsToAttack);
}


#include "Player.h"

Player::Player(const string& _name, const u_int& _gridSize,
    ShipData* _shipData, const u_int& _shipDataCount)
{
    name = _name;
    ownGrid = new Grid(_gridSize);
    opponentGrid = new Grid(_gridSize);
    shipData = new ShipData[_shipDataCount];

    for (u_int _index = 0; _index < _shipDataCount; _index++)
    {
        shipData[_index].count = _shipData[_index].count;
        for (u_int _shipIndex = 0; _shipIndex < shipData[_index].count; _shipIndex++)
        {
            // Je place un bateau sur la grille
            Ship* _shipObject = _shipData[_index].ship;
            shipData[_index].ship = new Ship(_shipObject);
        }
    }
    shipDataCount = _shipDataCount;

    this->Init();
}

Player::~Player()
{
    delete ownGrid;
    delete opponentGrid;
    delete[] shipData;
}

void Player::Init()
{
    ownGrid->Init(false);
    opponentGrid->Init(true);

    // Pour chaque type de bateau
    for (u_int _index = 0; _index < shipDataCount; _index++)
    {
        // Pour chaque meme type de bateau
        for (u_int _shipIndex = 0; _shipIndex < shipData[_index].count; _shipIndex++)
        {
            // Je place un bateau sur la grille
            shipData[_index].ship->Setup(*ownGrid, 10);
        }
    }
}

Cordinates Player::GetCoordsToAttack()
{
    

    //TODO


    string _coordsText;
    do
    {
        DISPLAY("Ma grille", true);
        ownGrid->Display();

        SPACE;
        DISPLAY_LINE;
        SPACE;

        DISPLAY("Grille adverse", true);
        opponentGrid->Display();

        DISPLAY("Tu veux attaquer ou ?", true);
        _coordsText = GetLine();
        if (_coordsText.size() != 2)
        {
            CLEAR_SCREEN;
        }

    } while (_coordsText.size() != 2);
    char _posX = _coordsText[0];
    u_int _posY = _coordsText[1] - '1';

    
    return Cordinates(int(_posX - 'A'), _posY);
}

Tile* Player::AnalyseAttack(const Cordinates* _coordsToAttack)
{
    return ownGrid->CheckAttack(_coordsToAttack);
}

void Player::UpdateOpponentGrid(const Cordinates& _coordsToAttack, const Tile* _opponentTile)
{
    if (_opponentTile)
    {
        opponentGrid->SetTile(_coordsToAttack, *_opponentTile);
    }
    else 
    {
        opponentGrid->GetTile(&_coordsToAttack)->SetIsHit(true);
    }
}


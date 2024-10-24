#pragma once
#include "Grid.h"

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
    Ship* ship;

    ShipData() = default;

    ~ShipData()
    {
        delete ship;
    };
};

class Player
{
    string name;
	Grid* ownGrid;
	Grid* opponentGrid;
	ShipData* shipData;
    u_int shipDataCount;

public:
    Player() = default;
    Player(const string& _name, const u_int& _gridSize, ShipData* _shipData, const u_int& _shipDataCount);
    ~Player();
public:
    void Init();
    Cordinates GetCoordsToAttack();
    bool AnalyseAttack(const Cordinates* _coordsToAttack);
    void UpdateOpponentGrid(const Cordinates& _coordsToAttack, const bool _hasHit);
    void DisplayMyGrid();
    void DisplayOponnentGrid();
};


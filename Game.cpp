﻿#include "Game.h"

Game::Game(const string& _namePlayer1, const string& _namePlayer2)
{
    ShipData _shipData[] =
    {
        { 0, new Ship('1', AIRCRAFT_CARRIER) },
        { 0, new Ship('2', CRUISER)},
        { 0, new Ship('3', DESTROYER)},
        { 0, new Ship('4', SUBMARINE)},
        { 2, new Ship('5', PATROLER)},
    };

    const u_int& _gridSize = 10;
    const u_int& _shipDataCount = size(_shipData);
	player1 = new Player(_namePlayer1, _gridSize, _shipData, _shipDataCount);
	player2 = new Player(_namePlayer2, _gridSize, _shipData, _shipDataCount);
}

Game::~Game()
{
    delete player1;
    delete player2;
}

void Game::Launch()
{
    Tile* _opponentTile;

    Player* _players[] = {player1, player2};
    const u_int _playersCount = size(_players);
    u_int _playerIndex = GetRandomNumberInRange(_playersCount,1)-1;
    u_int _otherPlayerIndex;
    Player* _currentPlayer;
    Player* _otherPlayer;

    do
    {
        _currentPlayer = _players[_playerIndex];
        

        // Afin de faire 01 01 01 01 01 01 01 01 01 01 01 01 01 
        _otherPlayerIndex = (_playerIndex + 1) % _playersCount;
        // CLOCK MODULO
        DISPLAY("►Au joueur " + _currentPlayer->GetName() + " de jouer !", true);
        SPACE;
        const Cordinates& _coordsToAttack = _currentPlayer->GetCoordsToAttack();

        CLEAR_SCREEN;
        _otherPlayer = _players[_otherPlayerIndex];
        _opponentTile = _otherPlayer->AnalyseAttack(&_coordsToAttack);
        _currentPlayer->UpdateOpponentGrid(_coordsToAttack, _opponentTile);


        if (!_opponentTile)
        {
            _playerIndex++;
            _playerIndex %= _playersCount;
        }
    } while (_otherPlayer->IsOver());

    _currentPlayer->Display();
    DISPLAY(GREEN "LE GRAND GAGNANT EST " + _otherPlayer->GetName() + " BRAVO!" RESET, true);
}



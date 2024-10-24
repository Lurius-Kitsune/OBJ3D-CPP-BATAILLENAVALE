#include "Game.h"

Game::Game(const string& _namePlayer1, const string& _namePlayer2)
{
    ShipData _shipData[] =
    {
        { 1, new Ship('1', AIRCRAFT_CARRIER) },
        { 1, new Ship('2', CRUISER)},
        { 1, new Ship('3', DESTROYER)},
        { 1, new Ship('4', SUBMARINE)},
        { 1, new Ship('5', PATROLER)},
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

    do
    {
        Player* _currentPlayer = _players[_playerIndex];
        DISPLAY("-> Au joueur " + _currentPlayer->GetName() + " de jouer !", true);

        // Afin de faire 01 01 01 01 01 01 01 01 01 01 01 01 01 
        // CLOCK MODULO
        _otherPlayerIndex = (_playerIndex + 1) % _playersCount;
        
        const Cordinates& _coordsToAttack = _currentPlayer->GetCoordsToAttack();
        _opponentTile = _players[_otherPlayerIndex]->AnalyseAttack(&_coordsToAttack);
        _currentPlayer->UpdateOpponentGrid(_coordsToAttack, _opponentTile);


        if (!_opponentTile)
        {
            _playerIndex++;
            _playerIndex %= _playersCount;
        }
    } while (true);
}



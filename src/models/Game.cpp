#include "models/Game.hpp"

Game::Game(LogicObserver *observer) : board(new Board())
{
    board->subscribe(observer);
}

Game::~Game()
{
    delete board;
}

void Game::getValidMovements()
{
    std::cout << "Getting valid movements." << std::endl;
}

void Game::select(const Coordinate &coordinate)
{
    board->selectPiece(coordinate);
}

void Game::put(const Coordinate &coordinate)
{
    board->movePieceTo(coordinate);
}

bool Game::isEmpty(const Coordinate &coordiante)
{
    return board->isSquareEmpty(coordiante);
}

bool Game::isMovementValid(const Coordinate &coordinate)
{
    return board->isMovementValid(coordinate);
}

void Game::changeTurn()
{
    board->changeTurn();
}

void Game::removeCurrentPlayerPiece(const Coordinate &coordinate)
{
    board->removeCurrentPlayerPiece(coordinate);
}


void Game::removeRivalPlayerPiece(const Coordinate &coordinate)
{
    board->removeRivalPlayerPiece(coordinate);
}

void Game::initialize()
{
    board->initialize();
}

void Game::begin()
{
    board->begin();
}

void Game::end()
{
    board->end();
}

void Game::finalize()
{
    board->finalize();
}

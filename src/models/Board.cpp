#include "models/pieces/PiecesMapBuilder.hpp"
#include "models/Board.hpp"

#include <iostream>

Board::Board()
    : piecesMap(PiecesMapBuilder::build(this)),
      selectedPiece(nullptr),
      turn(new Turn())
{
}

Board::~Board()
{
    delete turn;
}

void Board::set(Piece *piece)
{
    this->selectedPiece = piece;
}

void Board::set(std::list<std::shared_ptr<Coordinate>> movementsSelectedPiece)
{
    this->movementsSelectedPiece = movementsSelectedPiece;
}

bool Board::isItEnemy(const Coordinate & /*coordinate*/) const
{
    return false;
}

bool Board::isBoxEmpty(const Coordinate & /*coordinate*/) const
{
    return false;
}

bool Board::someColor(const Coordinate & /*coordinate*/) const
{
    return false;
}

bool Board::isBoxOccupied(const Coordinate & /*coordinate*/) const
{
    return false;
}

void Board::add(Piece *enPassantPawns)
{
    mapPassantPawns[getCurrentPlayer()].push_back(std::shared_ptr<Piece>(enPassantPawns));
}

bool Board::isMovementValid(const Coordinate & /*coordinate*/)
{
    return false;
}

void Board::selectPiece(const Coordinate &coordinate)
{
    std::cout << "Piece selected at: " << coordinate << std::endl;
}

void Board::putPiece(const Coordinate &coordinate)
{
    std::cout << "Piece put at: " << coordinate << std::endl;
}

void Board::removeCurrentPlayerPiece(const Coordinate & /*coordinate*/)
{
    std::cout << "" << std::endl;
}

void Board::removeRivalPlayerPiece(const Coordinate & /*coordinate*/)
{
    std::cout << "" << std::endl;
}

void Board::changeTurn()
{
    turn->change();
}

Player Board::getCurrentPlayer()
{
    return turn->getCurrentPlayer();
}

Player Board::getRivalPlayer()
{
    return turn->getRivalPlayer();
}
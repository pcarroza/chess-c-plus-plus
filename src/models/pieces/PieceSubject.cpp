#include "models/pieces/PieceSubject.hpp"

void PieceSubject::subscribe(BoardObserver *boardObserver)
{
    this->boardObserver = boardObserver;
}

bool PieceSubject::isItEnemy(const Coordinate &coordinate)
{
    return boardObserver->isItEnemy(coordinate);
}

bool PieceSubject::sameColor(const Coordinate &coordinate)
{
    return boardObserver->someColor(coordinate);
}

bool PieceSubject::isBoxOccupied(const Coordinate &coordinate)
{
    return boardObserver->isBoxOccupied(coordinate);
}

void PieceSubject::addPassantPawn(Piece *enPassantPawn)
{
    boardObserver->add(enPassantPawn);
}

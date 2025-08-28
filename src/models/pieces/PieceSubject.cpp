#include "models/pieces/PieceSubject.hpp"

void PieceSubject::subscribe(BoardObserver *boardObserver)
{
    this->boardObserver = boardObserver;
}

bool PieceSubject::isEnemy(const Coordinate &coordinate) const
{
    return boardObserver->isEnemy(coordinate);
}

bool PieceSubject::sameColor(const Coordinate &coordinate) const
{
    return boardObserver->someColor(coordinate);
}

bool PieceSubject::isBoxOccupied(const Coordinate &coordinate) const
{
    return boardObserver->isSquareOccupied(coordinate);
}

void PieceSubject::notifyPassingPawn(Piece *enPassantPawn)
{
    boardObserver->add(enPassantPawn);
}

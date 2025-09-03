#include "models/pieces/PieceSubject.hpp"

void PieceSubject::subscribe(BoardObserver *boardObserver)
{
    this->boardObserver = boardObserver;
}

bool PieceSubject::isEnemy(const Coordinate &coordinate) const
{
    return boardObserver->isEnemy(coordinate);
}

bool PieceSubject::isSameColorPieceAt(const Coordinate &coordinate) const
{
    return boardObserver->isSameColorPieceAt(coordinate);
}

bool PieceSubject::isSquareOccupied(const Coordinate &coordinate) const
{
    return boardObserver->isSquareOccupied(coordinate);
}

void PieceSubject::notifyEnPassantPawn(Piece *enPassantPawn)
{
    boardObserver->add(enPassantPawn);
}

void PieceSubject::notifyDeletedEnPassantPawn(Piece *piece)
{
    boardObserver->deleteEnPassantPawn(piece);
}

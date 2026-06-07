#include "models/modules/game/pieces/SubjectPiece.hpp"

namespace models::modules::game::pieces
{
    void SubjectPiece::subscribe(BoardObserver *boardObserver)
    {
        this->boardObserver = boardObserver;
    }

    bool SubjectPiece::isEnemy(const Coordinate &coordinate) const
    {
        return boardObserver->isEnemy(coordinate);
    }

    bool SubjectPiece::isItTheSameColorIn(const Coordinate &coordinate) const
    {
        return boardObserver->isSameColorPieceAt(coordinate);
    }

    bool SubjectPiece::isSquareOccupied(const Coordinate &coordinate) const
    {
        return boardObserver->isSquareOccupied(coordinate);
    }

    void SubjectPiece::notifyPawnInStep(Piece *pawnInStep)
    {
        boardObserver->add(pawnInStep);
    }

    void SubjectPiece::notifyDeletedPawnInStep(Piece *piece)
    {
        boardObserver->remove(piece);
    }
}

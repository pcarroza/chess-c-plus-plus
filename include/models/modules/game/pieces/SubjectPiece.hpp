#ifndef PIECE_SUBJECT_HPP
#define PIECE_SUBJECT_HPP

#include "BoardObserver.hpp"
#include "Coordinate.hpp"

namespace models::modules::game::pieces
{
    class SubjectPiece
    {
    public:
        virtual ~SubjectPiece() = default;

        void subscribe(BoardObserver *boardObserver);

        bool isEnemy(const Coordinate &coordinate) const;

        bool isItTheSameColorIn(const Coordinate &coordinate) const;

        bool isSquareOccupied(const Coordinate &coordinate) const;

        void notifyPawnInStep(Piece *piece);

        void notifyDeletedPawnInStep(Piece *piece);

    protected:
        BoardObserver *boardObserver;
    };
}

#endif

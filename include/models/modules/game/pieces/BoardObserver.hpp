#ifndef BOARD_OBSERVER_HPP
#define BOARD_OBSERVER_HPP

#include <vector>
#include <memory>

namespace models::modules::game::pieces {
    class Piece;
    class Coordinate;
}

namespace models::modules::game::pieces
{
    class BoardObserver
    {
    public:
        virtual ~BoardObserver() = default;

        virtual void add(Piece *enPassantPawn) = 0;

        virtual void deletedPawnInStep(Piece *piece) = 0;

        virtual bool isEnemy(const Coordinate &coordinate) = 0;

        virtual bool isSquareEmpty(const Coordinate &coordinate) = 0;

        virtual bool isSquareOccupied(const Coordinate &coordinate) = 0;

        virtual bool isSameColorPieceAt(const Coordinate &coordinate) = 0;
    };
}

#endif

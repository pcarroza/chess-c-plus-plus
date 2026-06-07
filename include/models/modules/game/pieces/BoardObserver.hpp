#ifndef BOARD_OBSERVER_HPP
#define BOARD_OBSERVER_HPP

#include <vector>
#include <memory>

namespace models::modules::game::pieces
{
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

        virtual void remove(Piece *piece) = 0;

        virtual bool isEnemy(const Coordinate &coordinate) const = 0;

        virtual bool isRookAvailableForCastling(const Coordinate &coordinate) const = 0;

        virtual bool isVulnerablePawnAt(const Coordinate &coordinate) const = 0;

        virtual bool isOccupied(const Coordinate &coordinate) const = 0;

        virtual bool isSquareEmpty(const Coordinate &coordinate) const = 0;

        virtual bool isSquareOccupied(const Coordinate &coordinate) const = 0;

        virtual bool isSameColorPieceAt(const Coordinate &coordinate) const = 0;

        virtual bool isKingInCheck() const = 0;
    };
}

#endif

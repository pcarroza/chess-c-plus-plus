#ifndef KING_H
#define KING_H

#include "Piece.hpp"
#include "models/modules/game/Player.hpp"

namespace models::modules::game::pieces
{
    class Coordinate;
    class PieceVisitor;
}

namespace models::modules::game::pieces
{
    class King : public Piece
    {
    public:
        King(Coordinate coordinate, Player player);

        void put(Coordinate target) override;

        bool isMovementValid(const Coordinate &target) const override;

        void close();

        bool isKing() const override;

        PieceSymbol getSymbol() const override;

    private:
        bool isMoved = false;
    };
}

#endif

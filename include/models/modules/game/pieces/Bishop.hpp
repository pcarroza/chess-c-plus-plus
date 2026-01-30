#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.hpp"
#include "models/modules/game/Player.hpp"

namespace models::modules::game::pieces
{
    class Coordinate;
    class PieceVisitor;
}

namespace models::modules::game::pieces
{
    class Bishop : public Piece
    {
    public:
        Bishop(Coordinate *coordinate, Player color);

        void accept(PieceVisitor &visitor) override;

        std::string toString() const override;
    };
}

#endif

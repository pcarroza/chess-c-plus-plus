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
        King(Coordinate *coordinate, Player color);

        void accept(PieceVisitor &pieceVisitor) override;

        std::string toString() const override;
    };
}

#endif

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"
#include "models/modules/game/Player.hpp"

namespace models::modules::game::pieces
{
    class Coordinate;
    class PieceVisitor;
}

namespace models::modules::game::pieces
{
    class Knight : public Piece
    {
    public:
        Knight(Coordinate coordinate, Player player);

        PieceSimbol getSymbol() override;
    };
}

#endif

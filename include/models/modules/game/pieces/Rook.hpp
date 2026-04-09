#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"
#include "Coordinate.hpp"
#include "models/modules/game/Player.hpp"

using models::modules::game::Player;

namespace models::modules::game::pieces
{
    class Rook : public Piece
    {
    public:
        Rook(Coordinate coordinate, Player player);

        PieceSymbol getSymbol() const override;
    };
}

#endif

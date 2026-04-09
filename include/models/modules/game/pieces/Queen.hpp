#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"
#include "Coordinate.hpp"
#include "models/modules/game/Player.hpp"

using models::modules::game::Player;

namespace models::modules::game::pieces
{
    class Queen : public Piece
    {
    public:
        Queen(Coordinate coordinate, Player player);

        PieceSimbol getSymbol() override;
    };
}

#endif

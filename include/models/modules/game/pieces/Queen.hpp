#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"
#include "Coordinate.hpp"
#include "models/modules/game/Player.hpp"
#include "PieceVisitor.hpp"

using models::modules::game::Player;

namespace models::modules::game::pieces
{
    class Queen : public Piece
    {
    public:
        Queen(Coordinate coordinate, Player player);

        void accept(PieceVisitor &pieceVisitor) override;

        std::string toString() const override;
    };
}

#endif

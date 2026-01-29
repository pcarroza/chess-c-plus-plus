#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"
#include "Coordinate.hpp"
#include "models/modules/game/Player.hpp"
#include "PieceVisitor.hpp"

using models::modules::game::Player;

namespace models::modules::game::pieces
{
    class Knight : public Piece
    {
    public:
        Knight(Coordinate *coordinate, Player color);

        void accept(PieceVisitor &visitor) override;

        std::string toString() const override;
    };
}

#endif

#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"
#include "Coordinate.hpp"
#include "models/modules/game/Player.hpp"
#include "PieceVisitor.hpp"

namespace models::modules::game::pieces
{
    using ::models::modules::game::Player;

    class Rook : public Piece
    {
    public:
        Rook(Coordinate *coordinate, Player color);

        void accept(PieceVisitor &visitor) override;

        std::string toString() const override;
    };
}

#endif

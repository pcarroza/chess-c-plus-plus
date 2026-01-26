#ifndef KING_H
#define KING_H

#include "Piece.hpp"
#include "Coordinate.hpp"
#include "models/modules/game/Player.hpp"
#include "PieceVisitor.hpp"

namespace models::modules::game::pieces
{
    using ::models::modules::game::Player;

    class King : public Piece
    {
    public:
        King(Coordinate *coordinate, Player color);

        void accept(PieceVisitor &visitor) override;

        std::string toString() const override;
    };
}

#endif

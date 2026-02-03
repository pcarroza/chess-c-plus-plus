#ifndef PIECE_INSPECTOR_HPP
#define PIECE_INSPECTOR_HPP

#include <memory>

namespace models::modules::game::pieces
{
    class Piece;
}

using models::modules::game::pieces::Piece;

namespace models::modules::game::pieces
{
    bool isPawnVulnerable(Piece &piece);

    bool isPawnPromoted(Piece &piece);

    bool isKing(Piece &piece);

    bool isRook(Piece &piece);
}

#endif

#ifndef PIECE_INSPECTOR_HPP
#define PIECE_INSPECTOR_HPP

#include <memory>
#include "Piece.hpp"

namespace models::modules::game::pieces
{
    class PieceInspector
    {
    public:
        ~PieceInspector() = delete;

        static bool isPawnVulnerable(Piece &piece);

        static bool isPawnPromoted(Piece &piece);

        static bool isKing(Piece &piece);

        static bool isRook(Piece &piece);

    private:
    };
}

#endif

#ifndef PIECE_SIMBOL_HPP
#define PIECE_SIMBOL_HPP

#include <string>

namespace models::modules::game::pieces::enums
{

    enum class PieceSimbol
    {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING,
        EMPTY
    };

    inline std::string getPieceSimbolValue(PieceSimbol symbol)
    {
        switch (symbol)
        {
        case PieceSimbol::PAWN:
            return "P";
        case PieceSimbol::ROOK:
            return "T";
        case PieceSimbol::KNIGHT:
            return "C";
        case PieceSimbol::BISHOP:
            return "B";
        case PieceSimbol::QUEEN:
            return "Q";
        case PieceSimbol::KING:
            return "K";
        case PieceSimbol::EMPTY:
            return ".";
        default:
            return "";
        }
    }
}

#endif

#ifndef PIECE_SIMBOL_HPP
#define PIECE_SIMBOL_HPP

#include <string>

namespace models::modules::game::pieces::enums
{

    enum class PieceSymbol
    {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING,
        EMPTY
    };

    inline std::string getPieceSimbolValue(PieceSymbol symbol)
    {
        switch (symbol)
        {
        case PieceSymbol::PAWN:
            return "P";
        case PieceSymbol::ROOK:
            return "T";
        case PieceSymbol::KNIGHT:
            return "C";
        case PieceSymbol::BISHOP:
            return "B";
        case PieceSymbol::QUEEN:
            return "Q";
        case PieceSymbol::KING:
            return "K";
        case PieceSymbol::EMPTY:
            return ".";
        default:
            return "";
        }
    }
}

#endif

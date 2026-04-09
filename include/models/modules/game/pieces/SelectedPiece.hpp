#ifndef SELECTED_PIECE_HPP
#define SELECTED_PIECE_HPP

#include "Coordinate.hpp"
#include "./enums/PieceSimbol.hpp"

#include <vector>

namespace models::modules::game::pieces
{
    using enums::PieceSimbol;

    class SelectedPiece
    {
    public:
        virtual ~SelectedPiece() = default;

        virtual void put(Coordinate coordinate) = 0;

        virtual bool isMovementValid(const Coordinate &coordinate) = 0;

        virtual void generateMovements() = 0;

        virtual PieceSimbol getSymbol() = 0;

        virtual Coordinate getCoordinate() = 0;

        virtual std::vector<Coordinate> getMovements() = 0;

        virtual std::vector<Coordinate> getEnPassantDiagonals() = 0;

        virtual bool isMovementValid(Coordinate coordinate) = 0;

        virtual bool isRookAvailableForCastling() = 0;

        virtual bool isKing() = 0;

        virtual bool isPawn() = 0;

        virtual bool isRook() = 0;

        virtual bool isPromoted() = 0;

        virtual bool isPawnPromoted() = 0;
    };
}

#endif
#ifndef SELECTED_PIECE_HPP
#define SELECTED_PIECE_HPP

#include "Coordinate.hpp"
#include "./enums/PieceSymbol.hpp"

#include <vector>

namespace models::modules::game::pieces
{
    using enums::PieceSymbol;

    class SelectedPiece
    {
    public:
        virtual ~SelectedPiece() = default;

        virtual void put(Coordinate coordinate) = 0;

        virtual void generateMovements() = 0;

        virtual PieceSymbol getSymbol() const = 0;

        virtual std::vector<Coordinate> getMovements() const = 0;

        virtual std::vector<Coordinate> getInStepDiagonals() const = 0;

        virtual bool isMovementValid(const Coordinate &coordinate) const = 0;

        virtual bool isRookAvailableForCastling() const = 0;

        virtual bool isKing() const = 0;

        virtual bool isPawn() const = 0;

        virtual bool isRook() const = 0;

        virtual bool isPromoted() const = 0;

        virtual bool isPawnPromoted() const = 0;
    };
}

#endif
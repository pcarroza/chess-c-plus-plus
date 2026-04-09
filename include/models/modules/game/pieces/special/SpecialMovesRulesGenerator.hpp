// ...existing code...
#ifndef SPECIALMOVESRULESGENERATOR_HPP
#define SPECIALMOVESRULESGENERATOR_HPP

#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Piece.hpp"

#include <vector>
#include <memory>
#include <algorithm>

namespace models::modules::game::pieces
{
    class Piece;
    class Coordinate;
}

namespace models::modules::game::pieces::special
{
    class SpecialMovesRulesGenerator
    {
    public:
        SpecialMovesRulesGenerator(Piece *piece);

        virtual ~SpecialMovesRulesGenerator() = default;

        virtual void generate() = 0;

        std::vector<Coordinate> getValidMovements();

        bool isMovementValid(const Coordinate &coordinate) const;

    private:
        bool isContained(const Coordinate &coordinate) const;

    protected:
        std::vector<Coordinate> possibleMoves;

        Piece *piece;
    };
}

#endif

#ifndef SPECIALMOVESRULESGENERATOR_HPP
#define SPECIALMOVESRULESGENERATOR_HPP

#include "models/pieces/Coordinate.hpp"
#include "models/pieces/Piece.hpp"

#include <list>
#include <memory>
#include <algorithm>

class Coordinate;
class Piece;

namespace models::pieces::specialRuleMovements
{
    class SpecialMovesRulesGenerator
    {
    public:
        SpecialMovesRulesGenerator(Piece *piece);

        virtual ~SpecialMovesRulesGenerator() = default;

        virtual void generate() = 0;

        std::list<std::shared_ptr<Coordinate>> getValidMovements();

        bool isMovementValid(const Coordinate &coordinate);

    private:
        bool isContained(const Coordinate &coordinate);

    protected:
        std::list<std::shared_ptr<Coordinate>> possibleMoves;

        Piece *piece;
    };
}

#endif

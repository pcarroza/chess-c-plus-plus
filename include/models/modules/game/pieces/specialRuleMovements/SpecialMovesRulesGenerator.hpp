#ifndef SPECIALMOVESRULESGENERATOR_HPP
#define SPECIALMOVESRULESGENERATOR_HPP

#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Piece.hpp"

#include <list>
#include <memory>
#include <algorithm>

namespace models::modules::game::pieces {
    class Piece;
    class Coordinate;
}

namespace models::modules::game::pieces::specialRuleMovements
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

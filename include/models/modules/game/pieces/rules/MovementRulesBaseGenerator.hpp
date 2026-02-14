#ifndef MOVE_RULES_MANAGER_HPP
#define MOVE_RULES_MANAGER_HPP

#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Piece.hpp"

#include <list>
#include <memory>
#include <algorithm>

namespace models::modules::game::pieces
{
    class Piece;
    class Coordinate;
}

namespace models::modules::game::pieces::rules
{
    class MovementRulesBaseGenerator
    {
    public:
        MovementRulesBaseGenerator();

        virtual ~MovementRulesBaseGenerator() = default;

        bool isMovementValid(const Coordinate &coordinate);

        std::list<std::shared_ptr<Coordinate>> &getMovements();

        virtual void generate(const Piece &piece) = 0;

    private:
        bool isContained(const Coordinate &coordinate);

    protected:
        std::list<std::shared_ptr<Coordinate>> possibleMoves;
    };
}

#endif

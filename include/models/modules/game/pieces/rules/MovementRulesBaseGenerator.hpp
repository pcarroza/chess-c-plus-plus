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

        MovementRulesBaseGenerator(Piece *piece);

        virtual ~MovementRulesBaseGenerator() = default;

        virtual void set(Piece *piece);

        std::list<std::shared_ptr<Coordinate>> &getValidMovements();

        bool isMovementValid(const Coordinate &coordinate);

        virtual void generate() = 0;

    private:
        bool isContained(const Coordinate &coordinate);

    protected:
        Piece *piece;

        std::list<std::shared_ptr<Coordinate>> possibleMoves;
    };
}

#endif

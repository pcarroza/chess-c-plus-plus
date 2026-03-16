#ifndef MOVEMENT_RULES_GENERATOR_HPP
#define MOVEMENT_RULES_GENERATOR_HPP

#include "models/modules/game/pieces/Coordinate.hpp"

#include <list>
#include <memory>
#include <algorithm>

namespace models::modules::game::pieces
{
    class Piece;
}

namespace models::modules::game::pieces::rules
{
    class MovementRulesGenerator
    {
    public:
        virtual ~MovementRulesGenerator() = default;

        virtual std::list<std::shared_ptr<Coordinate>> generate(const Piece &piece) const = 0;
    };
}

#endif

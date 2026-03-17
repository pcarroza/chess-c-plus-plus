#ifndef MOVEMENT_RULES_GENERATOR_HPP
#define MOVEMENT_RULES_GENERATOR_HPP

#include "models/modules/game/pieces/Coordinate.hpp"

#include <vector>
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

        virtual void generate(const Piece &piece, std::vector<Coordinate> &movements) const = 0;
    };
}

#endif

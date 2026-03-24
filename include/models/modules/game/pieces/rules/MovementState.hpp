#ifndef MOVEMENT_STATE_HPP
#define MOVEMENT_STATE_HPP

#include <vector>
#include "models/modules/game/pieces/Coordinate.hpp"

using models::modules::game::pieces::Coordinate;
using models::modules::game::pieces::Pawn;

namespace models::modules::game::pieces
{
    class Pawn;
}

namespace models::modules::game::pieces::rules
{
    class MovementState
    {
    public:
        virtual ~MovementState() = default;

        virtual void execute(const Pawn &pawn, std::vector<Coordinate> &movements) const = 0;
    };
}

#endif

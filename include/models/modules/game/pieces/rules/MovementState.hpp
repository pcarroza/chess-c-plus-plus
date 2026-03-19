#ifndef MOVEMENT_STATE_HPP
#define MOVEMENT_STATE_HPP

#include <vector>
#include "models/modules/game/pieces/Coordinate.hpp"

namespace models::modules::game::pieces
{
    class Pawn;
}

namespace models::modules::game::pieces::rules
{

    using models::modules::game::pieces::Pawn;
    using models::modules::game::pieces::Coordinate;

    class MovementState
    {
    public:
        virtual ~MovementState() = default;
        virtual void execute(const Pawn &pawn, std::vector<Coordinate> &movements) const = 0;
    };

}

#endif

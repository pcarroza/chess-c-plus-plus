#include "models/modules/game/pieces/rules/strategies/InverseMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include <vector>
#include <cassert>

namespace models::modules::game::pieces::rules::strategies
{
    InverseMovementStrategy::InverseMovementStrategy(const Piece &piece) : MovementStrategy(piece)
    {
    }

    void InverseMovementStrategy::generate(std::vector<Coordinate> &movements)
    {
        MovementStrategy::generate(Coordinate(1, -1), movements);
        MovementStrategy::generate(Coordinate(-1, 1), movements);
    }

    Coordinate InverseMovementStrategy::getDisplacedCoordinateBy(int step, const Coordinate &vector)
    {
        assert(step >= 1);
        return piece.getDisplacedBy(Coordinate(step, step), vector);
    }
}

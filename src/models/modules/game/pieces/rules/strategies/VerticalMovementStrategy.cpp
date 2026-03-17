#include "models/modules/game/pieces/rules/strategies/VerticalMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include <vector>
#include <cassert>

namespace models::modules::game::pieces::rules::strategies
{
    VerticalMovementStrategy::VerticalMovementStrategy(const Piece &piece) : MovementStrategy(piece)
    {
    }

    void VerticalMovementStrategy::generate(std::vector<Coordinate> &movements)
    {
        MovementStrategy::generate(Coordinate(1, 1), movements);
        MovementStrategy::generate(Coordinate(-1, 1), movements);
    }

    Coordinate VerticalMovementStrategy::getDisplacedCoordinateBy(int increment, const Coordinate &vector)
    {
        return piece.getDisplacedBy(Coordinate(increment, 0), vector);
    }
}

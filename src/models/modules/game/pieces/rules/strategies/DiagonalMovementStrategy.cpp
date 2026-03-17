#include "models/modules/game/pieces/rules/strategies/DiagonalMovementStrategy.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include <vector>

namespace models::modules::game::pieces::rules::strategies
{
    DiagonalMovementStrategy::DiagonalMovementStrategy(const Piece &piece) : MovementStrategy(piece)
    {
    }

    void DiagonalMovementStrategy::generate(std::vector<Coordinate> &movements)
    {
        MovementStrategy::generate(Coordinate(1, 1), movements);
        MovementStrategy::generate(Coordinate(-1, -1), movements);
    }

    Coordinate DiagonalMovementStrategy::getDisplacedCoordinateBy(int increment, const Coordinate &vector)
    {
        return piece.getDisplacedBy(Coordinate(increment, increment), vector);
    }
}

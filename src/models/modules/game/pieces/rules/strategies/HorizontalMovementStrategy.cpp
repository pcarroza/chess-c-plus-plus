#include "models/modules/game/pieces/rules/strategies/HorizontalMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include <vector>

namespace models::modules::game::pieces::rules::strategies
{

    HorizontalMovementStrategy::HorizontalMovementStrategy(const Piece &piece) : MovementStrategy(piece)
    {
    }

    void HorizontalMovementStrategy::generate(std::vector<Coordinate> &movements)
    {
        MovementStrategy::generate(Coordinate(1, 1), movements);
        MovementStrategy::generate(Coordinate(1, -1), movements);
    }

    Coordinate HorizontalMovementStrategy::getDisplacedCoordinateBy(int step, const Coordinate &vector)
    {
        return piece.getDisplacedBy(Coordinate(step, 0), vector);
    }
}

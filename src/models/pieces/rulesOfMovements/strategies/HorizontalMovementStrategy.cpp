#include "models/pieces/rulesOfMovements/strategies/HorizontalMovementStrategy.hpp"
#include "models/pieces/Piece.hpp"
#include "models/pieces/Coordinate.hpp"

#include <cassert>

namespace models::pieces::rulesOfMovements::strategies
{

    HorizontalMovementStrategy::HorizontalMovementStrategy(Piece *piece) : MovementStrategy(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> HorizontalMovementStrategy::generate()
    {
        std::list<std::shared_ptr<Coordinate>> movements;

        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(1, 1)));
        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(1, -1)));

        return movements;
    }

    Coordinate *HorizontalMovementStrategy::getDisplacedCoordinateBy(int step, const Coordinate &vector)
    {
        return piece->getDisplacedBy(Coordinate(step, 0), vector);
    }
}

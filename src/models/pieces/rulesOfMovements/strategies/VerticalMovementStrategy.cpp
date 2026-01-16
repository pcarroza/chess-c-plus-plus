#include "models/pieces/rulesOfMovements/strategies/VerticalMovementStrategy.hpp"
#include "models/pieces/Piece.hpp"
#include "models/pieces/Coordinate.hpp"
#include <cassert>

namespace models::pieces::rulesOfMovements::strategies
{
    VerticalMovementStrategy::VerticalMovementStrategy(Piece *piece) : MovementStrategy(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> VerticalMovementStrategy::generate()
    {
        std::list<std::shared_ptr<Coordinate>> movements;

        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(1, 1)));
        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(-1, 1)));

        return movements;
    }

    Coordinate *VerticalMovementStrategy::getDisplacedCoordinateBy(int increment, const Coordinate &vector)
    {
        return piece->getDisplacedBy(Coordinate(increment, 0), vector);
    }
}

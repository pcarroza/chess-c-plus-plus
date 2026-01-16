#include "models/pieces/rulesOfMovements/strategies/DiagonalMovementStrategy.hpp"
#include "models/pieces/Coordinate.hpp"

namespace models::pieces::rulesOfMovements::strategies
{
    DiagonalMovementStrategy::DiagonalMovementStrategy(Piece *piece) : MovementStrategy(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> DiagonalMovementStrategy::generate()
    {
        std::list<std::shared_ptr<Coordinate>> movements;

        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(1, 1)));
        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(-1, -1)));

        return movements;
    }

    Coordinate *DiagonalMovementStrategy::getDisplacedCoordinateBy(int increment, const Coordinate &vector)
    {
        return piece->getDisplacedBy(Coordinate(increment, increment), vector);
    }
}

#include "models/modules/game/pieces/rulesOfMovements/strategies/InverseMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"

#include <cassert>

namespace models::modules::game::pieces::rulesOfMovements::strategies
{
    InverseMovementStrategy::InverseMovementStrategy(Piece *piece) : MovementStrategy(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> InverseMovementStrategy::generate()
    {
        std::list<std::shared_ptr<Coordinate>> movements;

        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(1, -1)));
        movements.splice(movements.end(), MovementStrategy::generate(Coordinate(-1, 1)));

        return movements;
    }

    Coordinate *InverseMovementStrategy::getDisplacedCoordinateBy(int step, const Coordinate &vector)
    {
        assert(step >= 1);
        return piece->getDisplacedBy(Coordinate(step, step));
    }
}
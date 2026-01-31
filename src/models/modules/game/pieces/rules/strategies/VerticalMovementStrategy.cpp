#include "models/modules/game/pieces/rules/strategies/VerticalMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include <cassert>

namespace models::modules::game::pieces::rules::strategies
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

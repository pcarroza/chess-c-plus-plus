#include "models/modules/game/pieces/rules/strategies/HorizontalMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"

#include <cassert>

namespace models::modules::game::pieces::rules::strategies
{

    HorizontalMovementStrategy::HorizontalMovementStrategy(const Piece &piece) : MovementStrategy(piece)
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
        return piece.getDisplacedBy(Coordinate(step, 0), vector);
    }
}

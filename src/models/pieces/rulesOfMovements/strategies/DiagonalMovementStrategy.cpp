#include "models/pieces/rulesOfMovements/strategies/DiagonalMovementStrategy.hpp"
#include "models/pieces/rulesOfMovements/strategies/HorizontalMovementStrategy.hpp"

namespace models::pieces::rulesOfMovements::strategies
{
    std::list<std::shared_ptr<Coordinate>> DiagonalMovementStrategy::generatePseudoCoordinates(Piece &piece)
    {
        return std::list<std::shared_ptr<Coordinate>>();
    }

}

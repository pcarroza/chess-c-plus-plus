#include "models/pieces/rulesOfMovements/strategies/MovementStrategy.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/pieces/Coordinate.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::pieces::rulesOfMovements::strategies
{

    MovementStrategy::MovementStrategy(Piece *piece) : piece(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> MovementStrategy::generate(Coordinate *coordinate)
    {
        return std::list<std::shared_ptr<Coordinate>>();
    }

    std::list<std::shared_ptr<Coordinate>> MovementStrategy::generateRecursive(
        std::list<std::shared_ptr<Coordinate>> coordinates,
        Coordinate &vector,
        int step)
    {
        Coordinate &coordinate = getDisplacedCoordinateBy(step, vector);

        if (!ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinates.back()))
        {
            return;
        }
        if (piece->isSameColorPieceAt(coordinate))
        {
            return;
        }
        if (piece->isEnemy(coordinate))
        {
            coordinates.push_back(std::shared_ptr<Coordinate>(new Coordinate(coordinate)));
            return coordinates;
        }
        coordinates.push_back(std::shared_ptr<Coordinate>(new Coordinate(coordinate)));
        return generateRecursive(coordinates, vector, step + 1);
    }
}

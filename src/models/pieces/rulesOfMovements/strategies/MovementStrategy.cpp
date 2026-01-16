#include "models/pieces/rulesOfMovements/strategies/MovementStrategy.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/pieces/Coordinate.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::pieces::rulesOfMovements::strategies
{
    MovementStrategy::MovementStrategy(Piece *piece) : piece(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> MovementStrategy::generate(const Coordinate &vector)
    {
        std::list<std::shared_ptr<Coordinate>> coordinates;
        generateRecursive(coordinates, vector, 1);
        return coordinates;
    }

    void MovementStrategy::generateRecursive(std::list<std::shared_ptr<Coordinate>> &coordinates, const Coordinate &vector, int step)
    {
        Coordinate *coordinate = getDisplacedCoordinateBy(step, vector);
        if (not ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate))
        {
            return;
        }
        if (piece->isSameColorPieceAt(*coordinate))
        {
            return;
        }
        if (piece->isEnemy(*coordinate))
        {
            coordinates.push_back(std::shared_ptr<Coordinate>(new Coordinate(*coordinate)));
            return;
        }
        coordinates.push_back(std::shared_ptr<Coordinate>(new Coordinate(*coordinate)));
        delete coordinate;
        return generateRecursive(coordinates, vector, step + 1);
    }
}

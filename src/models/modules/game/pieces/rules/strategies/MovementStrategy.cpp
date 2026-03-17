#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include <vector>

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules::strategies
{
    MovementStrategy::MovementStrategy(const Piece &piece) : piece(piece)
    {
    }

    void MovementStrategy::generate(const Coordinate &vector, std::vector<Coordinate> &movements)
    {
        generateRecursive(movements, vector, 1);
    }

    void MovementStrategy::generateRecursive(std::vector<Coordinate> &coordinates, const Coordinate &vector, int step)
    {
        Coordinate coordinate = getDisplacedCoordinateBy(step, vector);
        if (not ValidatorLimitsBoard::getInstance().isWithinLimits(coordinate))
        {
            return;
        }
        if (piece.isItTheSameColorIn(coordinate))
        {
            return;
        }
        if (piece.isEnemy(coordinate))
        {
            coordinates.push_back(coordinate);
            return;
        }
        coordinates.push_back(coordinate);
        return generateRecursive(coordinates, vector, step + 1);
    }
}

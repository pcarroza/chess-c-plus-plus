#include "models/modules/game/pieces/rules/KingRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    void KingRules::generate(const Piece &piece, std::vector<Coordinate> &movements) const
    {
        const int simpleStep = 1;
        const int column = 0;

        const Coordinate offsets[] = {
            Coordinate(simpleStep, simpleStep),
            Coordinate(simpleStep, column),
            Coordinate(simpleStep, -simpleStep),
            Coordinate(column, simpleStep),
            Coordinate(column, -simpleStep),
            Coordinate(-simpleStep, simpleStep),
            Coordinate(-simpleStep, column),
            Coordinate(-simpleStep, -simpleStep)};

        for (const auto &offset : offsets)
        {
            Coordinate target = piece.getDisplacedBy(offset);
            if (ValidatorLimitsBoard::getInstance().isWithinLimits(target) and not piece.isItTheSameColorIn(target))
            {
                movements.push_back(target);
            }
        }
    }
}

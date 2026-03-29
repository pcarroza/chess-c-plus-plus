#include "models/modules/game/pieces/rules/KnightRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    void KnightRules::generate(const Piece &piece, std::vector<Coordinate> &movements) const
    {
        const int doubleStep = 2;
        const int simpleStep = 1;

        const Coordinate offsets[] = {
            Coordinate(doubleStep, simpleStep),
            Coordinate(doubleStep, -simpleStep),
            Coordinate(-doubleStep, simpleStep),
            Coordinate(-doubleStep, -simpleStep),
            Coordinate(simpleStep, doubleStep),
            Coordinate(simpleStep, -doubleStep),
            Coordinate(-simpleStep, doubleStep),
            Coordinate(-simpleStep, -doubleStep)};

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

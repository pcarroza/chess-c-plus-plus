#include "models/modules/game/pieces/rules/PawnRules.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    void PawnRules::generate(const Piece &piece, std::vector<Coordinate> &movements) const
    {
        const Pawn &pawn = dynamic_cast<const Pawn &>(piece);

        if (pawn.canAdvanceOne())
        {
            Coordinate target = pawn.getForwardOne();
            if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                movements.push_back(target);
        }

        if (pawn.canAdvanceTwo())
        {
            Coordinate target = pawn.getForwardTwo();
            if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                movements.push_back(target);
        }

        if (pawn.canCaptureLeft())
        {
            Coordinate target = pawn.getDiagonalLeft();
            if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                movements.push_back(target);
        }

        if (pawn.canCaptureRight())
        {
            Coordinate target = pawn.getDiagonalRight();
            if (ValidatorLimitsBoard::getInstance().isWithinLimits(target))
                movements.push_back(target);
        }
    }
}

#include "models/modules/game/pieces/rules/PawnRules.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    std::list<std::shared_ptr<Coordinate>> PawnRules::generate(const Piece &piece) const
    {
        const Pawn &pawn = dynamic_cast<const Pawn &>(piece);
        std::list<std::shared_ptr<Coordinate>> possibleMoves;

        if (pawn.canAdvanceOne())
            possibleMoves.push_back(pawn.getForwardOne());

        if (pawn.canAdvanceTwo())
            possibleMoves.push_back(pawn.getForwardTwo());

        if (pawn.canCaptureLeft())
            possibleMoves.push_back(pawn.getDiagonalLeft());

        if (pawn.canCaptureRight())
            possibleMoves.push_back(pawn.getDiagonalRight());

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return not ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });

        return possibleMoves;
    }
}

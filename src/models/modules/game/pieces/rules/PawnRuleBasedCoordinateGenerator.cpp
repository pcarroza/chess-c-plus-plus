#include "models/modules/game/pieces/rules/PawnRuleBasedCoordinateGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    PawnRuleBasedCoordinateGenerator::PawnRuleBasedCoordinateGenerator()
    {
    }

    void PawnRuleBasedCoordinateGenerator::generate(const Piece &piece)
    {
        const Pawn &pawn = dynamic_cast<const Pawn &>(piece);
        possibleMoves.clear();

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
    }
}

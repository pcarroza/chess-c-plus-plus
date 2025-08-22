#include "models/pieces/rulesOfMovements/PawnRuleBasedCoordinateGenerator.hpp"

namespace models::pieces::rulesOfMovements
{
    PawnRuleBasedCoordinateGenerator::PawnRuleBasedCoordinateGenerator(Piece *piece)
    {
        set(piece);
    }

    void PawnRuleBasedCoordinateGenerator::set(Piece *piece)
    {
        pawn = dynamic_cast<Pawn *>(piece);
    }

    void PawnRuleBasedCoordinateGenerator::generate()
    {
        possibleMoves.clear();

        if (pawn->canAdvanceOne())
            possibleMoves.push_back(pawn->getForwardOne());

        if (pawn->canAdvanceTwo())
            possibleMoves.push_back(pawn->getForwardTwo());

        if (pawn->canCaptureLeft())
            possibleMoves.push_back(pawn->getDiagonalLeft());

        if (pawn->canCaptureRight())
            possibleMoves.push_back(pawn->getDiagonalRight());

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return !ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });
    }
}

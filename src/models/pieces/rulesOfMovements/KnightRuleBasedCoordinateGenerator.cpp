#include "models/pieces/rulesOfMovements/KnightRuleBasedCoordinateGenerator.hpp"
#include <memory>

namespace models::pieces::rulesOfMovements
{
    KnightRuleBasedCoordinateGenerator::KnightRuleBasedCoordinateGenerator(Piece *piece)
        : MovementRulesBaseGenerator(piece)
    {
    }

    void KnightRuleBasedCoordinateGenerator::generate()
    {
        const int doubleStep = 2;
        const int simpleStep = 1;

        possibleMoves.clear();

        possibleMoves = {
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(doubleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(doubleStep, -simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-doubleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-doubleStep, -simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, doubleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, -doubleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, doubleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, -doubleStep)))};

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return !ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });

        possibleMoves.remove_if([this](const std::shared_ptr<Coordinate> &coordinate)
                                { return piece->isSameColorPieceAt(*coordinate); });
    }
}

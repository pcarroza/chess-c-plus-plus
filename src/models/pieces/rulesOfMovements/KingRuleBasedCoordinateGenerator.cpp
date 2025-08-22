#include "models/pieces/rulesOfMovements/KingRuleBasedCoordinateGenerator.hpp"

namespace models::pieces::rulesOfMovements
{
    KingRuleBasedCoordinateGenerator::KingRuleBasedCoordinateGenerator(Piece *piece)
        : MovementRulesBaseGenerator(piece)
    {
    }

    void KingRuleBasedCoordinateGenerator::generate()
    {
        const int simpleStep = 1;

        possibleMoves.clear();

        possibleMoves = {
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, 0))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, -simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(0, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(0, -simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, 0))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, -simpleStep)))};

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return !ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });

        possibleMoves.remove_if([this](const std::shared_ptr<Coordinate> &coordinate)
                                { return piece->sameColor(*coordinate); });
    }
}

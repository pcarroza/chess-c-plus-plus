#include "models/modules/game/pieces/rules/KingRuleBasedCoordinateGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    KingRuleBasedCoordinateGenerator::KingRuleBasedCoordinateGenerator(Piece *piece)
        : MovementRulesBaseGenerator(piece)
    {
    }

    void KingRuleBasedCoordinateGenerator::generate()
    {
        const int simpleStep = 1;
        const int column = 0;

        possibleMoves.clear();

        possibleMoves = {
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, column))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(simpleStep, -simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(column, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(column, -simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, column))),
            std::shared_ptr<Coordinate>(piece->getDisplacedBy(Coordinate(-simpleStep, -simpleStep)))};

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return not ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });

        possibleMoves.remove_if([this](const std::shared_ptr<Coordinate> &coordinate)
                                { return piece->isSameColorPieceAt(*coordinate); });
    }
}

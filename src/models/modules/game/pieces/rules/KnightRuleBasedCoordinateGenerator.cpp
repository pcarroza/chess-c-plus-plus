#include "models/modules/game/pieces/rules/KnightRuleBasedCoordinateGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    KnightRuleBasedCoordinateGenerator::KnightRuleBasedCoordinateGenerator()
    {
    }

    void KnightRuleBasedCoordinateGenerator::generate(const Piece &piece)
    {
        const int doubleStep = 2;
        const int simpleStep = 1;

        possibleMoves.clear();

        possibleMoves = {
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(doubleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(doubleStep, -simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(-doubleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(-doubleStep, -simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(simpleStep, doubleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(simpleStep, -doubleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(-simpleStep, doubleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(-simpleStep, -doubleStep)))};

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return not ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });

        possibleMoves.remove_if([&](const std::shared_ptr<Coordinate> &coordinate)
                                { return piece.isItTheSameColorIn(*coordinate); });
    }
}

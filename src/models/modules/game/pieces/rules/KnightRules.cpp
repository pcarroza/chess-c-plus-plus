#include "models/modules/game/pieces/rules/KnightRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    std::list<std::shared_ptr<Coordinate>> KnightRules::generate(const Piece &piece) const
    {
        const int doubleStep = 2;
        const int simpleStep = 1;

        std::list<std::shared_ptr<Coordinate>> possibleMoves = {
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

        return possibleMoves;
    }
}

#include "models/modules/game/pieces/rules/KingRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    std::list<std::shared_ptr<Coordinate>> KingRules::generate(const Piece &piece) const
    {
        const int simpleStep = 1;
        const int column = 0;

        std::list<std::shared_ptr<Coordinate>> possibleMoves = {
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(simpleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(simpleStep, column))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(simpleStep, -simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(column, simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(column, -simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(-simpleStep, simpleStep))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(-simpleStep, column))),
            std::shared_ptr<Coordinate>(piece.getDisplacedBy(Coordinate(-simpleStep, -simpleStep)))};

        possibleMoves.remove_if([](const std::shared_ptr<Coordinate> &coordinate)
                                { return not ValidatorLimitsBoard::getInstance().isWithinLimits(*coordinate); });

        possibleMoves.remove_if([&](const std::shared_ptr<Coordinate> &coordinate)
                                { return piece.isItTheSameColorIn(*coordinate); });

        return possibleMoves;
    }
}

#ifndef VALIDATOR_LIMITS_BOARD_HPP
#define VALIDATOR_LIMITS_BOARD_HPP

#include "common/constants/BoardConstants.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "ClosedInterval.hpp"

using common::constants::MAX_LIMIT;
using models::modules::game::pieces::Coordinate;

namespace common::validators
{
    class ValidatorLimitsBoard
    {
    public:
        static ValidatorLimitsBoard &getInstance();

        bool isWithinLimits(const Coordinate &coordinate);

        bool isPieceEndBoardAt(const Coordinate &coordinate);

    private:
        ValidatorLimitsBoard();

        ValidatorLimitsBoard(const ValidatorLimitsBoard &) = delete;

        ValidatorLimitsBoard &operator=(const ValidatorLimitsBoard &) = delete;

        ClosedInterval LIMITS;
    };
}

#endif
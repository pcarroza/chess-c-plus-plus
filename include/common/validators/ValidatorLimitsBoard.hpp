#ifndef VALIDATOR_LIMITS_BOARD_HPP
#define VALIDATOR_LIMITS_BOARD_HPP

#include "common/constants/BoardConstants.hpp"
#include "models/pieces/Coordinate.hpp"
#include "ClosedInterval.hpp"

class Coordinate;

using common::constants::MAX_LIMIT;

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
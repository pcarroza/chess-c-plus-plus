#include "common/validators/ValidatorLimitsBoard.hpp"

namespace common::validators
{
    ValidatorLimitsBoard &ValidatorLimitsBoard::getInstance()
    {
        static ValidatorLimitsBoard instance; // C++11 garantiza inicialización thread-safe
        return instance;
    }

    ValidatorLimitsBoard::ValidatorLimitsBoard() : LIMITS(1, MAX_LIMIT)
    {
    }

    bool ValidatorLimitsBoard::isWithinLimits(const Coordinate &coordinate)
    {
        return LIMITS.isIncluded(coordinate.getRow()) and
               LIMITS.isIncluded(coordinate.getColumn());
    }

    bool ValidatorLimitsBoard::isPieceEndBoardAt(const Coordinate &coordinate)
    {
        return LIMITS.isEqualToMin(coordinate.getRow()) or
               LIMITS.isEqualToMax(coordinate.getColumn());
    }
}
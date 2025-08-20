#include "common/validators/ClosedInterval.hpp"

namespace common::validators
{
    ClosedInterval::ClosedInterval(int min, int max) : min(min), max(max)
    {
    }

    bool ClosedInterval::isIncluded(int value) const
    {
        return min <= value && value <= max;
    }

    bool ClosedInterval::isEqualToMin(int value) const
    {
        return value == min;
    }

    bool ClosedInterval::isEqualToMax(int value) const
    {
        return value == max;
    }
}

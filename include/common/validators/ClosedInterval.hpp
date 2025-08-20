#ifndef CLOSED_INTERVAL_HPP
#define CLOSED_INTERVAL_HPP

namespace common::validators
{
    class ClosedInterval
    {
    public:
        ClosedInterval(int min, int max);

        bool isIncluded(int value) const;

        bool isEqualToMin(int value) const;

        bool isEqualToMax(int value) const;

    private:
        int min;

        int max;
    };
}

#endif

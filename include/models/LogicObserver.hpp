#ifndef LOGIC_OBSERVER_HPP
#define LOGIC_OBSERVER_HPP

namespace models
{
    class LogicObserver
    {
    public:
        virtual ~LogicObserver() = default;

        virtual void initialize() = 0;

        virtual void begin() = 0;

        virtual void finalize() = 0;

        virtual void end() = 0;
    };
}

#endif

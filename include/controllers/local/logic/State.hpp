#ifndef STATE_HPP
#define STATE_HPP

#include <cassert>

namespace controllers::local
{
    class LocalOperationController;
}

namespace controllers::local::logic
{
    class StateBuilder;
}

namespace controllers::local::logic
{
    class State
    {

    public:
        State(StateBuilder *stateBuilder);

        virtual ~State() = default;

        virtual State *initialize();

        virtual State *begin();

        virtual State *finalize();

        virtual State *end();

        virtual LocalOperationController *getController() const = 0;

    protected:
        StateBuilder *stateBuilder;
    };
}

#endif

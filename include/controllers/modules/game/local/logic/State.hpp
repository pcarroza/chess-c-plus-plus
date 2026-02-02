#ifndef STATE_HPP
#define STATE_HPP

#include <cassert>

namespace controllers::modules::game::local
{
    class LocalOperationController;
}

namespace controllers::modules::game::local::logic
{
    class StateBuilder;
}

namespace controllers::modules::game::local::logic
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
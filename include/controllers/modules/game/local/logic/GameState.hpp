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
    class GameState
    {
    public:
        GameState(StateBuilder *stateBuilder);

        virtual ~GameState() = default;

        virtual GameState *initialize();

        virtual GameState *begin();

        virtual GameState *finalize();

        virtual GameState *end();

        virtual LocalOperationController *getController() const = 0;

    protected:
        StateBuilder *stateBuilder;
    };
}

#endif
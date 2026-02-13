#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <cassert>

namespace controllers::modules::game::local
{
    class LocalOperationController;
}

namespace controllers::modules::game::local::logic
{
    class GameStateBuilder;
}

namespace controllers::modules::game::local::logic
{
    class GameState
    {
    public:
        GameState(GameStateBuilder *gameStateBuilder);

        virtual ~GameState() = default;

        virtual GameState *initialize();

        virtual GameState *begin();

        virtual GameState *finalize();

        virtual GameState *end();

        virtual LocalOperationController *getController() const = 0;

    protected:
        GameStateBuilder *gameStateBuilder;
    };
}

#endif
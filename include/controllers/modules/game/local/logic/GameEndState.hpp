#ifndef GAME_END_STATE_HPP
#define GAME_END_STATE_HPP

#include "GameState.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationController;
}

namespace controllers::modules::game::local::logic
{
    class GameEndState : public GameState
    {
    public:
        GameEndState(GameStateBuilder *gameStateBuilder);

        LocalOperationController *getController() const override;
    };
}

#endif

#ifndef INITIAL_STATE_HPP
#define INITIAL_STATE_HPP

#include "GameState.hpp"
#include "InGameState.hpp"
#include "GameStateBuilder.hpp"
#include "../LocalStartController.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationControllerBuilder;
    class LocalOperationController;
}

using controllers::modules::game::local::LocalOperationController;

namespace controllers::modules::game::local::logic
{
    class GameInitialState : public GameState
    {
    public:
        GameInitialState(GameStateBuilder *gameStateBuilder, LocalOperationControllerBuilder *builder);

        GameState *begin() override;

        LocalOperationController *getController() const override;

    private:
        LocalStartController *localStartController;
    };
}

#endif

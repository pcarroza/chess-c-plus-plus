#ifndef IN_GAME_STATE_HPP
#define IN_GAME_STATE_HPP

#include "GameState.hpp"
#include "StateBuilder.hpp"
#include "controllers/modules/game/local/LocalOperationController.hpp"
#include "controllers/modules/game/local/LocalOperationControllerBuilder.hpp"
#include "controllers/modules/game/local/logic/FinalState.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationControllerBuilder;
}

namespace controllers::modules::game::local::logic
{
    class InGameState : public GameState
    {
    public:
        InGameState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder);

        GameState *finalize() override;

        LocalOperationController *getController() const override;

    private:
        LocalOperationControllerBuilder *builder;

    };
}

#endif

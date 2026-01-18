#ifndef IN_GAME_STATE_HPP
#define IN_GAME_STATE_HPP

#include "State.hpp"
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
    class InGameState : public State
    {
    public:
        InGameState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder);

        State *finalize() override;

        LocalOperationController *getController() const override;

    private:
        LocalOperationControllerBuilder *builder;

    };
}

#endif

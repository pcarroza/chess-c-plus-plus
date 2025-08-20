#ifndef IN_GAME_STATE_HPP
#define IN_GAME_STATE_HPP

#include "State.hpp"
#include "StateBuilder.hpp"
#include "controllers/local/LocalOperationController.hpp"
#include "controllers/local/LocalOperationControllerBuilder.hpp"
#include "controllers/local/logic/FinalState.hpp"

namespace controllers::local
{
    class LocalOperationControllerBuilder;
}

namespace controllers::local::logic
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

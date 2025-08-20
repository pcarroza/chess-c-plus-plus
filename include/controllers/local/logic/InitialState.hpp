#ifndef INITIAL_STATE_HPP
#define INITIAL_STATE_HPP

#include "State.hpp"
#include "InGameState.hpp"
#include "StateBuilder.hpp"
#include "../LocalStartController.hpp"

namespace controllers::local
{
    class LocalOperationControllerBuilder;
    class LocalOperationController;
}

using controllers::local::LocalOperationController;

namespace controllers::local::logic
{
    class InitialState : public State
    {

    public:
        InitialState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder);

        State *begin() override;

        LocalOperationController *getController() const override;

    private:
        LocalStartController *localStartController;
    };
}

#endif

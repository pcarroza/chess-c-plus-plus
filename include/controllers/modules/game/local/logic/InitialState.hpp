#ifndef INITIAL_STATE_HPP
#define INITIAL_STATE_HPP

#include "State.hpp"
#include "InGameState.hpp"
#include "StateBuilder.hpp"
#include "../LocalStartController.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationControllerBuilder;
    class LocalOperationController;
}

using controllers::modules::game::local::LocalOperationController;

namespace controllers::modules::game::local::logic
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

#ifndef FINAL_STATE_HPP
#define FINAL_STATE_HPP

#include "controllers/local/LocalOperationControllerBuilder.hpp"
#include "controllers/local/LocalContinueController.hpp"
#include "controllers/local/logic/InitialState.hpp"
#include "controllers/local/logic/StateBuilder.hpp"
#include "controllers/local/logic/EndState.hpp"
#include "State.hpp"

namespace controllers::local::logic
{
    class FinalState : public State
    {
    public:
        FinalState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder);

        State *initialize() override;

        State *end() override;

        LocalOperationController *getController() const override;

    private:
        LocalContinueController *localContinueController;
    };
}

#endif

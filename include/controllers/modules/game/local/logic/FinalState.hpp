#ifndef FINAL_STATE_HPP
#define FINAL_STATE_HPP

#include "controllers/modules/game/local/LocalOperationControllerBuilder.hpp"
#include "controllers/modules/game/local/LocalContinueController.hpp"
#include "controllers/modules/game/local/logic/InitialState.hpp"
#include "controllers/modules/game/local/logic/StateBuilder.hpp"
#include "controllers/modules/game/local/logic/EndState.hpp"
#include "State.hpp"

namespace controllers::modules::game::local::logic
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

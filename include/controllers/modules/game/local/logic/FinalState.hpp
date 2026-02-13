#ifndef FINAL_STATE_HPP
#define FINAL_STATE_HPP

#include "controllers/modules/game/local/LocalOperationControllerBuilder.hpp"
#include "controllers/modules/game/local/LocalContinueController.hpp"
#include "controllers/modules/game/local/logic/InitialState.hpp"
#include "controllers/modules/game/local/logic/StateBuilder.hpp"
#include "controllers/modules/game/local/logic/EndState.hpp"
#include "GameState.hpp"

namespace controllers::modules::game::local::logic
{
    class FinalState : public GameState
    {
    public:
        FinalState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder);

        GameState *initialize() override;

        GameState *end() override;

        LocalOperationController *getController() const override;

    private:
        LocalContinueController *localContinueController;
    };
}

#endif

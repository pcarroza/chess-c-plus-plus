#ifndef GAME_FINAL_STATE_HPP
#define GAME_FINAL_STATE_HPP

#include "controllers/modules/game/local/LocalOperationControllerBuilder.hpp"
#include "controllers/modules/game/local/LocalContinueController.hpp"
#include "controllers/modules/game/local/logic/GameInitialState.hpp"
#include "controllers/modules/game/local/logic/GameStateBuilder.hpp"
#include "controllers/modules/game/local/logic/GameEndState.hpp"
#include "GameState.hpp"

namespace controllers::modules::game::local::logic
{
    class GameFinalState : public GameState
    {
    public:
        GameFinalState(GameStateBuilder *gameStateBuilder, LocalOperationControllerBuilder *builder);

        GameState *initialize() override;

        GameState *end() override;

        LocalOperationController *getController() const override;

    private:
        LocalContinueController *localContinueController;
    };
}

#endif

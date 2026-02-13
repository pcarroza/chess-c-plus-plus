#include "controllers/modules/game/local/logic/GameFinalState.hpp"

namespace controllers::modules::game::local::logic
{
    GameFinalState::GameFinalState(GameStateBuilder *gameStateBuilder, LocalOperationControllerBuilder *builder)
        : GameState(gameStateBuilder),
          localContinueController(builder->getContinueController())
    {
    }

    GameState *GameFinalState::initialize()
    {
        return gameStateBuilder->getInitialState();
    }

    GameState *GameFinalState::end()
    {
        return gameStateBuilder->getEndState();
    }

    LocalOperationController *GameFinalState::getController() const
    {
        return localContinueController;
    }
}

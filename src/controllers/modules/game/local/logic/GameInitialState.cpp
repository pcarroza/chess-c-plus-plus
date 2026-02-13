#include "controllers/modules/game/local/logic/GameInitialState.hpp"

namespace controllers::modules::game::local::logic
{
    GameInitialState::GameInitialState(GameStateBuilder *gameStateBuilder, LocalOperationControllerBuilder *builder)
        : GameState(gameStateBuilder),
          localStartController(builder->getStartController())
    {
    }

    GameState *GameInitialState::begin()
    {
        return gameStateBuilder->getInGameState();
    }

    LocalOperationController *GameInitialState::getController() const
    {
        return localStartController;
    }
}

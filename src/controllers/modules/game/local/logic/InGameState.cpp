#include "controllers/modules/game/local/logic/InGameState.hpp"

namespace controllers::modules::game::local::logic
{
    InGameState::InGameState(GameStateBuilder *gameStateBuilder, LocalOperationControllerBuilder *builder)
        : GameState(gameStateBuilder),
          builder(builder)
    {
    }

    GameState *InGameState::finalize()
    {
        return gameStateBuilder->getFinalState();
    }

    LocalOperationController *InGameState::getController() const
    {
        return builder->getPlacementController();
    }
}

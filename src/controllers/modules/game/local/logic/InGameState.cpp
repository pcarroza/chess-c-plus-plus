#include "controllers/modules/game/local/logic/InGameState.hpp"

namespace controllers::modules::game::local::logic
{
    InGameState::InGameState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder)
        : GameState(stateBuilder),
          builder(builder)
    {
    }

    GameState *InGameState::finalize()
    {
        return stateBuilder->getFinalState();
    }

    LocalOperationController *InGameState::getController() const
    {
        return builder->getPlacementController();
    }
}

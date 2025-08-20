#include "controllers/local/logic/InGameState.hpp"

namespace controllers::local::logic
{
    InGameState::InGameState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder)
        : State(stateBuilder),
          builder(builder)
    {
    }

    State *InGameState::finalize()
    {
        return stateBuilder->getFinalState();
    }

    LocalOperationController *InGameState::getController() const
    {
        return builder->getPlacementController();
    }
}

#include "controllers/local/logic/InitialState.hpp"

namespace controllers::local::logic
{
    InitialState::InitialState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder)
        : State(stateBuilder),
          localStartController(builder->getStartController())
    {
    }

    State *InitialState::begin()
    {
        return stateBuilder->getInGameState();
    }

    LocalOperationController *InitialState::getController() const
    {
        return localStartController;
    }
}

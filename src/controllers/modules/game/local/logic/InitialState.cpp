#include "controllers/modules/game/local/logic/InitialState.hpp"

namespace controllers::modules::game::local::logic
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

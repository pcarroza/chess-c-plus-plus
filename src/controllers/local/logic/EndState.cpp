#include "controllers/local/logic/EndState.hpp"

namespace controllers::local::logic
{
    EndState::EndState(StateBuilder *stateBuilder) : State(stateBuilder)
    {
    }

    LocalOperationController *EndState::getController() const
    {
        return nullptr;
    }
}

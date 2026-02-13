#include "controllers/modules/game/local/logic/EndState.hpp"

namespace controllers::modules::game::local::logic
{
    EndState::EndState(StateBuilder *stateBuilder) : GameState(stateBuilder)
    {
    }

    LocalOperationController *EndState::getController() const
    {
        return nullptr;
    }
}

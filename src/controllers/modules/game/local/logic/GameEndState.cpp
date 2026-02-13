#include "controllers/modules/game/local/logic/GameEndState.hpp"

namespace controllers::modules::game::local::logic
{
    GameEndState::GameEndState(GameStateBuilder *gameStateBuilder) : GameState(gameStateBuilder)
    {
    }

    LocalOperationController *GameEndState::getController() const
    {
        return nullptr;
    }
}

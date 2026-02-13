#include "controllers/modules/game/local/logic/GameState.hpp"

namespace controllers::modules::game::local::logic
{
    GameState::GameState(StateBuilder *stateBuilder) : stateBuilder(stateBuilder)
    {
    }

    GameState *GameState::initialize()
    {
        assert(false && "initialize() not implemented");
        return nullptr;
    }

    GameState *GameState::begin()
    {
        assert(false && "begin() not implemented");
        return nullptr;
    }

    GameState *GameState::finalize()
    {
        assert(false && "finalize() not implemented");
        return nullptr;
    }

    GameState *GameState::end()
    {
        assert(false && "end() not implemented");
        return nullptr;
    }
}

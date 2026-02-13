#include "controllers/modules/game/local/logic/GameStateBuilder.hpp"
#include "controllers/modules/game/local/logic/GameInitialState.hpp"
#include "controllers/modules/game/local/logic/InGameState.hpp"
#include "controllers/modules/game/local/logic/GameFinalState.hpp"
#include "controllers/modules/game/local/logic/GameEndState.hpp"

namespace controllers::modules::game::local::logic
{
    GameStateBuilder::GameStateBuilder(LocalOperationControllerBuilder *builder)
        : initialState(new GameInitialState(this, builder)),
          inGameState(new InGameState(this, builder)),
          finalState(new GameFinalState(this, builder)),
          endState(new GameEndState(this))
    {
    }

    GameStateBuilder::~GameStateBuilder()
    {
        delete initialState;
        delete inGameState;
        delete finalState;
        delete endState;
    }

    GameInitialState *GameStateBuilder::getInitialState()
    {
        return initialState;
    }

    InGameState *GameStateBuilder::getInGameState()
    {
        return inGameState;
    }

    GameFinalState *GameStateBuilder::getFinalState()
    {
        return finalState;
    }

    GameEndState *GameStateBuilder::getEndState()
    {
        return endState;
    }
}

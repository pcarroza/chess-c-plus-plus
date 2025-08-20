#include "controllers/local/logic/StateBuilder.hpp"
#include "controllers/local/logic/InitialState.hpp"
#include "controllers/local/logic/InGameState.hpp"
#include "controllers/local/logic/FinalState.hpp"
#include "controllers/local/logic/EndState.hpp"

namespace controllers::local::logic
{
    StateBuilder::StateBuilder(LocalOperationControllerBuilder *builder)
        : initialState(new InitialState(this, builder)),
          inGameState(new InGameState(this, builder)),
          finalState(new FinalState(this, builder)),
          endState(new EndState(this))
    {
    }

    StateBuilder::~StateBuilder()
    {
        delete initialState;
        delete inGameState;
        delete finalState;
        delete endState;
    }

    InitialState *StateBuilder::getInitialState()
    {
        return initialState;
    }

    InGameState *StateBuilder::getInGameState()
    {
        return inGameState;
    }

    FinalState *StateBuilder::getFinalState()
    {
        return finalState;
    }

    EndState *StateBuilder::getEndState()
    {
        return endState;
    }
}

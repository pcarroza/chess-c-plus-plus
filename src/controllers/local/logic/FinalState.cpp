#include "controllers/local/logic/FinalState.hpp"

namespace controllers::local::logic
{
    FinalState::FinalState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder)
        : State(stateBuilder),
          localContinueController(builder->getContinueController())
    {
    }

    State *FinalState::initialize()
    {
        return stateBuilder->getInitialState();
    }

    State *FinalState::end()
    {
        return stateBuilder->getEndState();
    }

    LocalOperationController *FinalState::getController() const
    {
        return localContinueController;
    }
}

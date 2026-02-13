#include "controllers/modules/game/local/logic/FinalState.hpp"

namespace controllers::modules::game::local::logic
{
    FinalState::FinalState(StateBuilder *stateBuilder, LocalOperationControllerBuilder *builder)
        : GameState(stateBuilder),
          localContinueController(builder->getContinueController())
    {
    }

    GameState *FinalState::initialize()
    {
        return stateBuilder->getInitialState();
    }

    GameState *FinalState::end()
    {
        return stateBuilder->getEndState();
    }

    LocalOperationController *FinalState::getController() const
    {
        return localContinueController;
    }
}

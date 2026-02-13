#ifndef END_STATE_HPP
#define END_STATE_HPP

#include "GameState.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationController;
}

namespace controllers::modules::game::local::logic
{
    class EndState : public GameState
    {
    public:
        EndState(StateBuilder *stateBuilder);

        LocalOperationController *getController() const override;
    };
}

#endif

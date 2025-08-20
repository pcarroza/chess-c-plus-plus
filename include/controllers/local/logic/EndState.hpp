#ifndef END_STATE_HPP
#define END_STATE_HPP

#include "State.hpp"

namespace controllers::local
{
    class LocalOperationController;
}

namespace controllers::local::logic
{
    class EndState : public State
    {

    public:
        EndState(StateBuilder *stateBuilder);

        LocalOperationController *getController() const override;
    };
}

#endif

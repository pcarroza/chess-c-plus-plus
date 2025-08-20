#ifndef STATE_BUILDER_HPP
#define STATE_BUILDER_HPP

namespace controllers::local
{
    class LocalOperationControllerBuilder;
}

namespace controllers::local::logic
{
    class InitialState;
    class InGameState;
    class FinalState;
    class EndState;
}

namespace controllers::local::logic
{
    class StateBuilder
    {

    public:
        StateBuilder(LocalOperationControllerBuilder *builder);

        ~StateBuilder();

        InitialState *getInitialState();

        InGameState *getInGameState();

        FinalState *getFinalState();

        EndState *getEndState();

    private:
        InitialState *initialState;

        InGameState *inGameState;

        FinalState *finalState;

        EndState *endState;
    };
}

#endif

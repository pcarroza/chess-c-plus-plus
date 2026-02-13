#ifndef GAME_STATE_BUILDER_HPP
#define GAME_STATE_BUILDER_HPP

namespace controllers::modules::game::local
{
    class LocalOperationControllerBuilder;
}

namespace controllers::modules::game::local::logic
{
    class GameInitialState;
    class InGameState;
    class GameFinalState;
    class GameEndState;
}

namespace controllers::modules::game::local::logic
{
    class GameStateBuilder
    {
    public:
        GameStateBuilder(LocalOperationControllerBuilder *builder);

        ~GameStateBuilder();

        GameInitialState *getInitialState();

        InGameState *getInGameState();

        GameFinalState *getFinalState();

        GameEndState *getEndState();

    private:
        GameInitialState *initialState;

        InGameState *inGameState;

        GameFinalState *finalState;

        GameEndState *endState;
    };
}

#endif

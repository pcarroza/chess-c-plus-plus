#include "controllers/modules/game/local/logic/LocalGameLogic.hpp"
#include "controllers/modules/game/local/LocalOperationControllerBuilder.hpp"
#include "controllers/modules/game/local/logic/StateBuilder.hpp"
#include "controllers/modules/game/local/logic/InitialState.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local::logic
{
    LocalGameLogic::LocalGameLogic()
        : game(new Game(this)),
          state(nullptr),
          stateBuilder(nullptr),
          builder(new LocalOperationControllerBuilder(*game))
    {
        builder->build();
        stateBuilder = new StateBuilder(builder);
        state = stateBuilder->getInitialState();
    }

    LocalGameLogic::~LocalGameLogic()
    {
        delete game;
        delete builder;
        delete stateBuilder;
    }

    void LocalGameLogic::initialize()
    {
        state = state->initialize();
    }

    void LocalGameLogic::begin()
    {
        state = state->begin();
    }

    void LocalGameLogic::finalize()
    {
        state = state->finalize();
    }

    void LocalGameLogic::end()
    {
        state = state->end();
    }

    LocalOperationController *LocalGameLogic::getController()
    {
        return state->getController();
    }
}

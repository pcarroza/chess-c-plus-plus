#include "controllers/local/LocalOperationControllerBuilder.hpp"
#include "controllers/local/logic/StateBuilder.hpp"
#include "controllers/local/logic/InitialState.hpp"
#include "controllers/local/logic/LocalLogic.hpp"
#include "models/Game.hpp"

namespace controllers::local::logic
{
    LocalLogic::LocalLogic()
        : game(new Game(this)),
          state(nullptr),
          stateBuilder(nullptr),
          localOperationControllerBuilder(new LocalOperationControllerBuilder(*game))
    {
        localOperationControllerBuilder->build();
        stateBuilder = new StateBuilder(localOperationControllerBuilder);
        state = stateBuilder->getInitialState();
    }

    LocalLogic::~LocalLogic()
    {
        delete game;
        delete localOperationControllerBuilder;
        delete stateBuilder;
    }

    void LocalLogic::initialize()
    {
        state = state->initialize();
    }

    void LocalLogic::begin()
    {
        state = state->begin();
    }

    void LocalLogic::finalize()
    {
        state = state->finalize();
    }

    void LocalLogic::end()
    {
        state = state->end();
    }

    LocalOperationController *LocalLogic::getController()
    {
        return state->getController();
    }
}
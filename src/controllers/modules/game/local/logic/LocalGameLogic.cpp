#include "controllers/modules/game/local/logic/LocalGameLogic.hpp"
#include "controllers/modules/game/local/LocalOperationControllerBuilder.hpp"
#include "controllers/modules/game/local/logic/GameStateBuilder.hpp"
#include "controllers/modules/game/local/logic/GameInitialState.hpp"
#include "models/modules/game/Game.hpp"
#include "controllers/modules/game/local/logic/LocalGameLogic.hpp"

namespace controllers::modules::game::local::logic
{
    LocalGameLogic::LocalGameLogic()
        : game(new Game(this)),
          state(nullptr),
          gameStateBuilder(nullptr),
          builder(new LocalOperationControllerBuilder(*game))
    {
        builder->build();
        gameStateBuilder = new GameStateBuilder(builder);
        state = gameStateBuilder->getInitialState();
    }

    LocalGameLogic::~LocalGameLogic()
    {
        delete game;
        delete builder;
        delete gameStateBuilder;
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

    void LocalGameLogic::save()
    {
    }

    void LocalGameLogic::resume()
    {
    }

    LocalOperationController *LocalGameLogic::getController()
    {
        return state->getController();
    }
}

#include "controllers/local/LocalStartController.hpp"
#include "controllers/local/LocalContinueController.hpp"
#include "controllers/local/LocalPlacementController.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPlacementControllerBuilder.hpp"
#include "controllers/local/LocalOperationControllerBuilder.hpp"

namespace controllers::local
{
    LocalOperationControllerBuilder::LocalOperationControllerBuilder(Game &game) : game(game)
    {
    }

    LocalOperationControllerBuilder::~LocalOperationControllerBuilder()
    {
        delete localStartController;
        delete localContinueController;
        builders.clear();
    }

    void LocalOperationControllerBuilder::build()
    {
        localStartController = new LocalStartController(game, this);
        builders.resize(Game::NUMBER_OF_PLAYERS);
        localContinueController = new LocalContinueController(game);
    }

    void LocalOperationControllerBuilder::build(int /*users*/)
    {
    }

    LocalStartController *LocalOperationControllerBuilder::getStartController()
    {
        return localStartController;
    }

    LocalOperationController *LocalOperationControllerBuilder::getPlacementController()
    {
        return nullptr;
    }

    LocalContinueController *LocalOperationControllerBuilder::getContinueController()
    {
        return localContinueController;
    }
}

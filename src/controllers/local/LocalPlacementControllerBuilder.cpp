#include "controllers/local/LocalPlacementControllerBuilder.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPutPieceController.hpp"
#include "controllers/local/LocalCoordinateController.hpp"
#include <memory>

namespace controllers::local
{
    LocalPlacementControllerBuilder::LocalPlacementControllerBuilder(Game &game) : game(game)
    {
    }

    LocalPlacementControllerBuilder::~LocalPlacementControllerBuilder()
    {
    }

    void LocalPlacementControllerBuilder::build(std::vector<std::unique_ptr<LocalCoordinateController>> localCoordinateControllers)
    {
        this->localCoordinateControllers = std::move(localCoordinateControllers);
        controllers.push_back(std::make_unique<LocalSelectPieceController>(game, this->localCoordinateControllers[0].get()));
        controllers.push_back(std::make_unique<LocalPutPieceController>(game, this->localCoordinateControllers[0].get()));
    }

    LocalPlacementController *LocalPlacementControllerBuilder::getPlacementController()
    {
        return nullptr;
    }

    Game &LocalPlacementControllerBuilder::getGame()
    {
        return game;
    }

}

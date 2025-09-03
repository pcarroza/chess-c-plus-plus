#include "controllers/local/LocalPlacementControllerBuilder.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPutPieceController.hpp"

namespace controllers::local
{
    LocalPlacementControllerBuilder::LocalPlacementControllerBuilder(Game &game) : game(game)
    {
    }

    LocalPlacementControllerBuilder::~LocalPlacementControllerBuilder()
    {
        for (LocalPlacementController *controller : controllers)
        {
            delete controller;
        }
        controllers.clear();
    }

    void LocalPlacementControllerBuilder::build(std::vector<LocalCoordinateController *> /*localCoordinateControllers*/)
    {
        // La implementación de la función debe ir aquí.
    }

    LocalPlacementController *LocalPlacementControllerBuilder::getPlacementController()
    {
        return nullptr;
    }
}

#include "controllers/local/LocalUserPlacementControllerBuilder.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPutPieceController.hpp"
#include "controllers/local/LocalUserCoordinateController.hpp"
#include <memory>

namespace controllers::local
{
    LocalUserPlacementControllerBuilder::LocalUserPlacementControllerBuilder(Game &game) : LocalPlacementControllerBuilder(game)
    {
    }

    void LocalUserPlacementControllerBuilder::build()
    {
        std::vector<std::unique_ptr<LocalCoordinateController>> localCoordinateControllers;
        localCoordinateControllers.push_back(std::make_unique<LocalUserCoordinateController>(this->getGame()));
        LocalPlacementControllerBuilder::build(std::move(localCoordinateControllers));
    }
}

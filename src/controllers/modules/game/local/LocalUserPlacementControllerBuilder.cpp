#include "controllers/modules/game/local/LocalUserPlacementControllerBuilder.hpp"
#include "controllers/modules/game/local/LocalSelectPieceController.hpp"
#include "controllers/modules/game/local/LocalPutPieceController.hpp"
#include "controllers/modules/game/local/LocalUserCoordinateController.hpp"
#include <memory>

namespace controllers::modules::game::local
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

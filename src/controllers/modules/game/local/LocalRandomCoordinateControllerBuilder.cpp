#include "controllers/modules/game/local/LocalRandomCoordinateControllerBuilder.hpp"
#include "controllers/modules/game/local/LocalSelectPieceController.hpp"
#include "controllers/modules/game/local/LocalPutPieceController.hpp"
#include "controllers/modules/game/local/LocalRandomCoordinateController.hpp"
#include <memory>

namespace controllers::modules::game::local
{
    LocalRandomCoordinateControllerBuilder::LocalRandomCoordinateControllerBuilder(Game &game) : LocalPlacementControllerBuilder(game)
    {
    }

    void LocalRandomCoordinateControllerBuilder::build()
    {
        std::vector<std::unique_ptr<LocalCoordinateController>> localCoordinateControllers;
        localCoordinateControllers.push_back(std::make_unique<LocalRandomCoordinateController>(this->getGame()));
        LocalPlacementControllerBuilder::build(std::move(localCoordinateControllers));
    }
}

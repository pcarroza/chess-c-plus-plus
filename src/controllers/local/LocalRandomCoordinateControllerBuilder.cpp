#include "controllers/local/LocalRandomCoordinateControllerBuilder.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPutPieceController.hpp"
#include "controllers/local/LocalRandomCoordinateController.hpp"
#include <memory>

namespace controllers::local
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

#include "controllers/local/LocalUserPlacementControllerBuilder.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPutPieceController.hpp"
#include "controllers/local/LocalUserCoordinateController.hpp"

namespace controllers::local
{
    LocalUserPlacementControllerBuilder::LocalUserPlacementControllerBuilder(Game &game) : LocalPlacementControllerBuilder(game)
    {
    }

    void LocalUserPlacementControllerBuilder::build()
    {
    }
}

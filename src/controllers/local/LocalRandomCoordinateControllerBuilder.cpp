#include "controllers/local/LocalRandomCoordinateControllerBuilder.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPutPieceController.hpp"
#include "controllers/local/LocalRandomCoordinateController.hpp"

namespace controllers::local
{
    LocalRandomCoordinateControllerBuilder::LocalRandomCoordinateControllerBuilder(Game &game) : LocalPlacementControllerBuilder(game)
    {
    }

    void LocalRandomCoordinateControllerBuilder::build()
    {
    }
}

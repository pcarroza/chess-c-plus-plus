#include "controllers/modules/game/local/LocalPutPieceController.hpp"
#include "controllers/modules/game/local/LocalCoordinateController.hpp"

namespace controllers::modules::game::local
{
    LocalPutPieceController::LocalPutPieceController(Game &game, LocalCoordinateController *coordenateController)
        : LocalPlacementController(game), localCoordinateController(coordenateController)
    {
    }

    void LocalPutPieceController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

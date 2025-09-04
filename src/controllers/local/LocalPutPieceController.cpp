#include "controllers/local/LocalPutPieceController.hpp"
#include "controllers/local/LocalCoordinateController.hpp"

namespace controllers::local
{

    LocalPutPieceController::LocalPutPieceController(Game &game, LocalCoordinateController *coordenateController) : LocalPlacementController(game), coordenateController(coordenateController)
    {
    }

    void LocalPutPieceController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

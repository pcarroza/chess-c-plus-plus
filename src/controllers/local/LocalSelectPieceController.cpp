#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalCoordinateController.hpp"

namespace controllers::local
{
    LocalSelectPieceController::LocalSelectPieceController(Game &game, LocalCoordinateController *coordenateController) : LocalPlacementController(game), coordenateController(coordenateController)
    {
    }

    void LocalSelectPieceController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

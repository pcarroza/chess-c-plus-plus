#include "controllers/local/LocalPutPieceController.hpp"

namespace controllers::local
{

    LocalPutPieceController::LocalPutPieceController(Game &game) : LocalPlacementController(game)
    {
    }

    void LocalPutPieceController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

#include "controllers/local/LocalSelectPieceController.hpp"

namespace controllers::local
{
    LocalSelectPieceController::LocalSelectPieceController(Game &game) : LocalPlacementController(game)
    {
    }

    void LocalSelectPieceController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

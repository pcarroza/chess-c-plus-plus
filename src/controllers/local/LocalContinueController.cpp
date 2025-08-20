#include "controllers/local/LocalContinueController.hpp"

namespace controllers::local
{
    LocalContinueController::LocalContinueController(Game &game) : LocalOperationController(game)
    {
    }

    void LocalContinueController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

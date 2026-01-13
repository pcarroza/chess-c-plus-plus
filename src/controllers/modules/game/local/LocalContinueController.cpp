#include "controllers/modules/game/local/LocalContinueController.hpp"

namespace controllers::modules::game::local
{
    LocalContinueController::LocalContinueController(Game &game) : LocalOperationController(game)
    {
    }

    void LocalContinueController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

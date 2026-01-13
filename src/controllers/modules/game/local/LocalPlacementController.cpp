#include "controllers/modules/game/local/LocalPlacementController.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"

namespace controllers::modules::game::local
{
    LocalPlacementController::LocalPlacementController(Game &game) : LocalOperationController(game)
    {
    }

    void LocalPlacementController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

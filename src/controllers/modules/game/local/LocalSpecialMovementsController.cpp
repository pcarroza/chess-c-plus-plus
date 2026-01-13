#include "controllers/modules/game/SpecialMovementsControllerVisitor.hpp"
#include "controllers/modules/game/local/LocalSpecialMovementsController.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"

namespace controllers::modules::game::local
{
    LocalSpecialMovementsController::LocalSpecialMovementsController(Game &game) : LocalPlacementController(game)
    {
    }

    bool LocalSpecialMovementsController::isApplicable()
    {
        return false;
    }

    void LocalSpecialMovementsController::accept(SpecialMovementsControllerVisitor *specialMovementsControllerVisitor)
    {
    }

    void LocalSpecialMovementsController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        LocalPlacementController::accept(operationControllerVisitor);
    }
}

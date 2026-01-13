#include "controllers/modules/game/local/LocalCastlingMovesController.hpp"
#include "controllers/modules/game/SpecialMovementsControllerVisitor.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"

namespace controllers::modules::game::local
{
    LocalCastlingMovesController::LocalCastlingMovesController(Game &game) : LocalPlacementController(game)
    {
    }

    void LocalCastlingMovesController::accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor)
    {
        specialMovementsControllerVisitor.visit(this);
    }

    void LocalCastlingMovesController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

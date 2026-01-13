#include "controllers/modules/game/SpecialMovementsControllerVisitor.hpp"
#include "controllers/modules/game/local/LocalEnPassantPawnController.hpp"
#include "controllers/modules/game/local/LocalPlacementController.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"

namespace controllers::modules::game::local
{
    LocalEnPassantPawnController::LocalEnPassantPawnController(Game &game) : LocalPlacementController(game)
    {
    }

    bool LocalEnPassantPawnController::isApplicable()
    {
        return false;
    }

    void LocalEnPassantPawnController::accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor)
    {
        specialMovementsControllerVisitor.visit(this);
    }

    void LocalEnPassantPawnController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

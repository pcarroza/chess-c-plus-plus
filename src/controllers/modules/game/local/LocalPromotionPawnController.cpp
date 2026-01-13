#include "controllers/modules/game/local/LocalSpecialMovementsController.hpp"
#include "controllers/modules/game/local/LocalPromotionPawnController.hpp"
#include "controllers/modules/game/SpecialMovementsControllerVisitor.hpp"
#include "controllers/modules/game/local/LocalPromotionPawnController.hpp"

namespace controllers::modules::game::local
{
    LocalPromotionPawnController::LocalPromotionPawnController(Game &game) : LocalPlacementController(game)
    {
    }

    bool LocalPromotionPawnController::isApplicable()
    {
        return false;
    }

    void LocalPromotionPawnController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }

    void LocalPromotionPawnController::accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor)
    {
        specialMovementsControllerVisitor.visit(this);
    }
}

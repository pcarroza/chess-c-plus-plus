#include "controllers/local/LocalSpecialMovementsController.hpp"
#include "controllers/local/LocalPromotionPawnController.hpp"
#include "controllers/SpecialMovementsControllerVisitor.hpp"

namespace controllers::local
{

    LocalPromotionPawnController::LocalPromotionPawnController(Game &game) : LocalPlacementController(game)
    {
    }

    bool LocalPromotionPawnController::isApplicable()
    {
        return false;
    }

    void LocalPromotionPawnController::accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor)
    {
        specialMovementsControllerVisitor.visit(this);
    }
}

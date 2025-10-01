#include "controllers/SpecialMovementsControllerVisitor.hpp"
#include "controllers/local/LocalSpecialMovementsController.hpp"

namespace controllers::local
{
    LocalSpecialMovementsController::LocalSpecialMovementsController(Game &game) : LocalPlacementController(game)
    {
    }

    bool LocalSpecialMovementsController::isApplicable()
    {
        return false;
    }
}

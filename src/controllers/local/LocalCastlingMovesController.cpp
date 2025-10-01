#include "controllers/local/LocalCastlingMovesController.hpp"
#include "controllers/SpecialMovementsControllerVisitor.hpp"

namespace controllers::local
{
    LocalCastlingMovesController::LocalCastlingMovesController(Game &game) : LocalPlacementController(game)
    {
    }

    void LocalCastlingMovesController::accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor)
    {
        specialMovementsControllerVisitor.visit(this);
    }
}

#include "controllers/SpecialMovementsControllerVisitor.hpp"
#include "controllers/local/LocalEnPassantPawnController.hpp"
#include "controllers/local/LocalPlacementController.hpp"

namespace controllers::local
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
}

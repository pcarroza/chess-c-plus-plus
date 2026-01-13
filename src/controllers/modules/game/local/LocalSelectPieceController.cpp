#include "controllers/modules/game/local/LocalSelectPieceController.hpp"
#include "controllers/modules/game/local/LocalCoordinateController.hpp"

namespace controllers::modules::game::local
{
    LocalSelectPieceController::LocalSelectPieceController(Game &game, LocalCoordinateController *coordenateController)
        : LocalPlacementController(game), coordenateController(coordenateController)
    {
    }

    void LocalSelectPieceController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

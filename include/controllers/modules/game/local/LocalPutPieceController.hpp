#ifndef LOCAL_PUT_PIECE_CONTROLLER_HPP
#define LOCAL_PUT_PIECE_CONTROLLER_HPP

#include "controllers/modules/game/PutPieceController.hpp"
#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local
{
    class LocalCoordinateController;

    class LocalPutPieceController : public LocalPlacementController, public PutPieceController
    {
    public:
        LocalPutPieceController(Game &game, LocalCoordinateController *coordenateController);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;

    private:
        LocalCoordinateController *localCoordinateController;
    };
}

#endif

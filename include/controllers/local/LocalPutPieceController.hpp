#ifndef LOCAL_PUT_PIECE_CONTROLLER_HPP
#define LOCAL_PUT_PIECE_CONTROLLER_HPP

#include "controllers/PutPieceController.hpp"
#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalCoordinateController;

    class LocalPutPieceController : public LocalPlacementController, public PutPieceController
    {
    public:
        LocalPutPieceController(Game &game, LocalCoordinateController *coordenateController);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;

    private:
        LocalCoordinateController *coordenateController;
    };
}

#endif

#ifndef LOCAL_SELECT_PIECE_CONTROLLER_HPP
#define LOCAL_SELECT_PIECE_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "controllers/SelectPieceController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalCoordinateController;

    class LocalSelectPieceController : public LocalPlacementController, public SelectPieceController
    {
    public:
        LocalSelectPieceController(Game &game, LocalCoordinateController *coordenateController);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;

    private:
        LocalCoordinateController *coordenateController;
    };
}

#endif

#ifndef LOCAL_PUT_PIECE_CONTROLLER_HPP
#define LOCAL_PUT_PIECE_CONTROLLER_HPP

#include "controllers/PutPieceController.hpp"
#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalPutPieceController : public LocalPlacementController, public PutPieceController
    {
    public:
        LocalPutPieceController(Game &game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

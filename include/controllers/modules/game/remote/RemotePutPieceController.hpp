#ifndef REMOTE_PUT_PIECE_CONTROLLER_HPP
#define REMOTE_PUT_PIECE_CONTROLLER_HPP

#include "controllers/modules/game/PutPieceController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemotePutPieceController : public PutPieceController, public RemoteOperationController
    {
    public:
        RemotePutPieceController(Game *game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

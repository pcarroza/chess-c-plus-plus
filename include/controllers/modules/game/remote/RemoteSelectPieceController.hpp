#ifndef REMOTE_SELECT_PIECE_CONTROLLER_HPP
#define REMOTE_SELECT_PIECE_CONTROLLER_HPP

#include "controllers/modules/game/SelectPieceController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteSelectPieceController : public SelectPieceController, public RemoteOperationController
    {
    public:
        RemoteSelectPieceController(Game *game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

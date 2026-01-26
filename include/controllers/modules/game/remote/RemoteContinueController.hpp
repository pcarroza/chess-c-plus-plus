#ifndef REMOTE_CONTINUE_CONTROLLER_HPP
#define REMOTE_CONTINUE_CONTROLLER_HPP

#include "controllers/modules/game/ContinueController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteContinueController : public ContinueController, public RemoteOperationController
    {
    public:
        RemoteContinueController(Game *game) : RemoteOperationController(game) {}

        void accept(OperationControllerVisitor &operationControllerVisitor) override
    };
}

#endif

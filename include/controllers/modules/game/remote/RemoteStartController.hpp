#ifndef REMOTE_START_CONTROLLER_HPP
#define REMOTE_START_CONTROLLER_HPP

#include "controllers/modules/game/StartController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteStartController : public StartController, public RemoteOperationController
    {
    public:
        RemoteStartController(Game *game);

        void start(int users) override;

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

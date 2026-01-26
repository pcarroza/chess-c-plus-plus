#ifndef REMOTE_COORDINATE_CONTROLLER_HPP
#define REMOTE_COORDINATE_CONTROLLER_HPP

#include "controllers/modules/game/OperationControllerVisitor.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteCoordinateController :  public RemoteOperationController
    {
    public:
        RemoteCoordinateController(Game *game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override
    };
}

#endif

#ifndef REMOTE_USER_COORDINATE_CONTROLLER_HPP
#define REMOTE_USER_COORDINATE_CONTROLLER_HPP

#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteUserCoordinateController : public RemoteOperationController
    {
    public:
        RemoteUserCoordinateController(Game *game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

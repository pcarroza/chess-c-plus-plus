#ifndef REMOTE_RANDOM_COORDINATE_CONTROLLER_HPP
#define REMOTE_RANDOM_COORDINATE_CONTROLLER_HPP

#include "controllers/modules/game/OperationControllerVisitor.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteRandomCoordinateController :  public RemoteOperationController
    {
    public:
        RemoteRandomCoordinateController(Game *game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

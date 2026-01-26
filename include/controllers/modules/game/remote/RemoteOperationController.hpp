#ifndef REMOTE_OPERATION_CONTROLLER_HPP
#define REMOTE_OPERATION_CONTROLLER_HPP

#include "RemoteController.hpp"
#include "controllers/modules/game/OperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteOperationController : public OperationController, public RemoteController
    {
    public:
        RemoteOperationController(Game *game);
        
    };
}

#endif

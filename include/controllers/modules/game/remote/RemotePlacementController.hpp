#ifndef REMOTE_PLACEMENT_CONTROLLER_HPP
#define REMOTE_PLACEMENT_CONTROLLER_HPP

#include "controllers/modules/game/PlacementController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemotePlacementController : public RemoteOperationController, public PlacementController
    {
    public:
        RemotePlacementController(Game *game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

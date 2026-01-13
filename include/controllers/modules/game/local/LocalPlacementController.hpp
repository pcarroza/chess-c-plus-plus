#ifndef LOCAL_PLACEMENT_CONTROLLER_HPP
#define LOCAL_PLACEMENT_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "controllers/modules/game/PlacementController.hpp"
#include "models/Game.hpp"

namespace controllers::modules::game::local
{
    class LocalPlacementController : public LocalOperationController, public PlacementController
    {
    public:
        LocalPlacementController(Game &game);

        virtual ~LocalPlacementController() = default;

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

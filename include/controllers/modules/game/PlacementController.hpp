#ifndef PLACEMENT_CONTROLLER_HPP
#define PLACEMENT_CONTROLLER_HPP

#include "models/modules/game/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

namespace controllers::modules::game
{
    class PlacementController : virtual public OperationController
    {
    public:
        virtual ~PlacementController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

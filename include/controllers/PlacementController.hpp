#ifndef PLACEMENT_CONTROLLER_HPP
#define PLACEMENT_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

namespace controllers
{
    class PlacementController : public OperationController
    {
    public:
        virtual ~PlacementController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

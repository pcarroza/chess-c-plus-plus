#ifndef SPECIAL_MOVEMENTS_CONTROLLER_HPP
#define SPECIAL_MOVEMENTS_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

namespace controllers
{
    class SpecialMovementsController : public OperationController
    {
    public:
        virtual ~SpecialMovementsController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

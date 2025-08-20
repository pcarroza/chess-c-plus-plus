#ifndef OPERATION_CONTROLLER_HPP
#define OPERATION_CONTROLLER_HPP

#include "./OperationControllerVisitor.hpp"
#include "models/Game.hpp"

namespace controllers
{
    class OperationController
    {
    public:
        virtual ~OperationController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

#ifndef OPERATION_CONTROLLER_HPP
#define OPERATION_CONTROLLER_HPP

#include "./OperationControllerVisitor.hpp"

namespace controllers::modules::game
{
    class OperationController
    {
    public:
        virtual ~OperationController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

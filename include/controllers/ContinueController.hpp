#ifndef CONTINUE_CONTROLLER_HPP
#define CONTINUE_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

namespace controllers
{
    class ContinueController : public OperationController
    {
    public:
        virtual ~ContinueController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

#ifndef START_CONTROLLER_HPP
#define START_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

namespace controllers
{
    class StartController : public OperationController
    {
    public:
        virtual ~StartController() = default;

        virtual void start(int users) = 0;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

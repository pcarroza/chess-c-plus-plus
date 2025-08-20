#ifndef LOCAL_OPERATION_CONTROLLER_HPP
#define LOCAL_OPERATION_CONTROLLER_HPP

#include "controllers/OperationControllerVisitor.hpp"
#include "controllers/OperationController.hpp"
#include "LocalController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalOperationController : public LocalController, public OperationController
    {

    public:
        LocalOperationController(Game &game);

        virtual ~LocalOperationController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

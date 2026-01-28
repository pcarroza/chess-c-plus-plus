#ifndef LOCAL_OPERATION_CONTROLLER_HPP
#define LOCAL_OPERATION_CONTROLLER_HPP

#include "controllers/modules/game/OperationControllerVisitor.hpp"
#include "controllers/modules/game/OperationController.hpp"
#include "LocalController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationController : public LocalController, virtual public OperationController
    {

    public:
        LocalOperationController(Game &game);

        virtual ~LocalOperationController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

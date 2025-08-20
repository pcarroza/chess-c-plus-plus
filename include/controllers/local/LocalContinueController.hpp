#ifndef LOCAL_CONTINUE_CONTROLLER_HPP
#define LOCAL_CONTINUE_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "controllers/ContinueController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalContinueController : public LocalOperationController, public ContinueController
    {
    public:
        LocalContinueController(Game &game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

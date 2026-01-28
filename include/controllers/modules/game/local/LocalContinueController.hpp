#ifndef LOCAL_CONTINUE_CONTROLLER_HPP
#define LOCAL_CONTINUE_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "controllers/modules/game/ContinueController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local
{
    class LocalContinueController : public LocalOperationController, public ContinueController
    {
    public:
        LocalContinueController(Game &game);

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

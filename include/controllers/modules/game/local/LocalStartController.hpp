#ifndef LOCAL_START_CONTROLLER_HPP
#define LOCAL_START_CONTROLLER_HPP

#include "LocalOperationControllerBuilder.hpp"
#include "LocalOperationController.hpp"
#include "controllers/modules/game/StartController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationControllerBuilder;
}

namespace controllers::modules::game::local
{
    class LocalStartController : public LocalOperationController, public StartController
    {
    public:
        LocalStartController(Game &game, LocalOperationControllerBuilder *builder);

        void start(int users) override;

        void accept(OperationControllerVisitor &operationControllerVisitor) override;

    private:
        LocalOperationControllerBuilder *localOperationControllerBuilder;
    };
}

#endif

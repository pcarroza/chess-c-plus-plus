#ifndef LOCAL_START_CONTROLLER_HPP
#define LOCAL_START_CONTROLLER_HPP

#include "LocalOperationControllerBuilder.hpp"
#include "LocalOperationController.hpp"
#include "controllers/StartController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalOperationControllerBuilder;

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

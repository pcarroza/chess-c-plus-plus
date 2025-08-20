#include "controllers/local/LocalStartController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    LocalStartController::LocalStartController(Game &game, LocalOperationControllerBuilder *builder)
        : LocalOperationController(game), localOperationControllerBuilder(builder)
    {
    }

    void LocalStartController::start(int users)
    {
        localOperationControllerBuilder->build(users);
    }

    void LocalStartController::accept(OperationControllerVisitor &operationControllerVisitor)
    {
        operationControllerVisitor.visit(this);
    }
}

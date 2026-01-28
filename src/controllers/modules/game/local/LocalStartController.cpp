#include "controllers/modules/game/local/LocalStartController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local
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

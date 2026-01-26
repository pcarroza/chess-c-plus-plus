#ifndef REMOTE_SPECIAL_MOVEMENTS_CONTROLLER_HPP
#define REMOTE_SPECIAL_MOVEMENTS_CONTROLLER_HPP

#include "controllers/modules/game/SpecialMovementsController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteSpecialMovementsController : public SpecialMovementsController, public RemoteOperationController
    {
    public:
        RemoteSpecialMovementsController(Game *game);

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override;
    };
}

#endif

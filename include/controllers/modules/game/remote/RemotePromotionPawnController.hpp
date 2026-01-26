#ifndef REMOTE_PROMOTION_PAWN_CONTROLLER_HPP
#define REMOTE_PROMOTION_PAWN_CONTROLLER_HPP

#include "controllers/modules/game/PromotionPawnController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemotePromotionPawnController : public PromotionPawnController, public RemoteOperationController
    {
    public:
        RemotePromotionPawnController(Game *game) : RemoteOperationController(game) {}

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override
    };
}

#endif

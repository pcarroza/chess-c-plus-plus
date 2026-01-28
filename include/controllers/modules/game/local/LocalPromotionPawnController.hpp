#ifndef LOCAL_PROMOTION_PAWN_CONTROLLER_HPP
#define LOCAL_PROMOTION_PAWN_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "controllers/modules/game/PromotionPawnController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers::modules::game::local
{
    class LocalPromotionPawnController : public LocalPlacementController, public PromotionPawnController
    {
    public:
        LocalPromotionPawnController(Game &game);

        bool isApplicable();

        void accept(OperationControllerVisitor &operationControllerVisitor) override;

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override;
    };
}

#endif

#ifndef LOCAL_PROMOTION_PAWN_CONTROLLER_HPP
#define LOCAL_PROMOTION_PAWN_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "controllers/PromotionPawnController.hpp"
#include "models/Game.hpp"

namespace controllers
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers::local
{
    class LocalPromotionPawnController : public LocalPlacementController, public PromotionPawnController
    {
    public:
        LocalPromotionPawnController(Game &game);

        bool isApplicable();

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override;
    };
}

#endif

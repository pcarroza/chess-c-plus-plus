#ifndef PROMOTION_PAWN_CONTROLLER_HPP
#define PROMOTION_PAWN_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"
#include "SpecialMovementsControllerVisitor.hpp"

namespace controllers::modules::game
{
    class PromotionPawnController : virtual public OperationController
    {
    public:
        virtual ~PromotionPawnController() = default;

        virtual void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) = 0;
    };
}

#endif

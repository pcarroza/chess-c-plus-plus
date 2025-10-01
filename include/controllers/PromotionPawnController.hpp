#ifndef PROMOTION_PAWN_CONTROLLER_HPP
#define PROMOTION_PAWN_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

namespace controllers
{
    class PromotionPawnController : public OperationController
    {
    public:
        virtual ~PromotionPawnController() = default;

        virtual void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) = 0;
    };
}

#endif

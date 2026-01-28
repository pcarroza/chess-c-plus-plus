#ifndef EN_PASSANT_PAWN_CONTROLLER_HPP
#define EN_PASSANT_PAWN_CONTROLLER_HPP

#include "models/modules/game/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"
#include "SpecialMovementsControllerVisitor.hpp"

namespace controllers::modules::game
{
    class EnPassantPawnController : virtual public OperationController
    {
    public:
        virtual ~EnPassantPawnController() = default;

        virtual void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) = 0;
    };
}

#endif

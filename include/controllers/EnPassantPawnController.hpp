#ifndef EN_PASSANT_PAWN_CONTROLLER_HPP
#define EN_PASSANT_PAWN_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"
#include "SpecialMovementsControllerVisitor.hpp"

namespace controllers
{
    class EnPassantPawnController : public OperationController
    {
    public:
        virtual ~EnPassantPawnController() = default;

        virtual void accept(SpecialMovementsControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

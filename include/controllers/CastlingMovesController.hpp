#ifndef CASTLING_MOVES_CONTROLLER_HPP
#define CASTLING_MOVES_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"

namespace controllers
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers
{
    class CastlingMovesController : public OperationController
    {

    public:
        virtual ~CastlingMovesController() = default;

        virtual void accept(SpecialMovementsControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

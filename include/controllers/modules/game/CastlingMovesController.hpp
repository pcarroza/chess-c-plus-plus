#ifndef CASTLING_MOVES_CONTROLLER_HPP
#define CASTLING_MOVES_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "SpecialMovementsControllerVisitor.hpp"

namespace controllers::modules::game
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers::modules::game
{
    class CastlingMovesController : virtual public OperationController
    {

    public:
        virtual ~CastlingMovesController() = default;

        virtual void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) = 0;
    };
}

#endif

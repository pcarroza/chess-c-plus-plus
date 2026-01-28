#ifndef SPECIAL_MOVEMENTS_CONTROLLER_HPP
#define SPECIAL_MOVEMENTS_CONTROLLER_HPP

#include "models/modules/game/Game.hpp"
#include "OperationController.hpp"
#include "SpecialMovementsControllerVisitor.hpp"

namespace controllers::modules::game
{
    class SpecialMovementsController : virtual public OperationController
    {
    public:
        virtual ~SpecialMovementsController() = default;

        virtual void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) = 0;
    };
}

#endif

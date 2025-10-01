#ifndef LOCAL_SPECIAL_MOVEMENTS_CONTROLLER_HPP
#define LOCAL_SPECIAL_MOVEMENTS_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "controllers/SpecialMovementsController.hpp"
#include "models/Game.hpp"

namespace controllers
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers::local
{
    class LocalSpecialMovementsController : public LocalPlacementController, public SpecialMovementsController
    {
    public:
        LocalSpecialMovementsController(Game &game);

        virtual bool isApplicable() = 0;

        virtual void accept(SpecialMovementsControllerVisitor *specialMovementsControllerVisitor) = 0;
    };
}

#endif

#ifndef LOCAL_SPECIAL_MOVEMENTS_CONTROLLER_HPP
#define LOCAL_SPECIAL_MOVEMENTS_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "models/modules/game/Game.hpp"
#include "controllers/modules/game/SpecialMovementsController.hpp"

namespace controllers
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers::modules::game::local
{
    class LocalSpecialMovementsController : public LocalPlacementController, public SpecialMovementsController
    {
    public:
        LocalSpecialMovementsController(Game &game);

        virtual bool isApplicable() = 0;

        virtual void accept(SpecialMovementsControllerVisitor *specialMovementsControllerVisitor) = 0;

        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

#ifndef LOCAL_EN_PASSANT_PAWN_CONTROLLER_HPP
#define LOCAL_EN_PASSANT_PAWN_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "controllers/modules/game/EnPassantPawnController.hpp"
#include "models/Game.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"
#include "controllers/modules/game/SpecialMovementsControllerVisitor.hpp"

namespace controllers::modules::game::local
{
    class LocalEnPassantPawnController : public LocalPlacementController, public EnPassantPawnController
    {
    public:
        LocalEnPassantPawnController(Game &game);

        bool isApplicable();

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override;
        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

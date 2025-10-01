#ifndef LOCAL_EN_PASSANT_PAWN_CONTROLLER_HPP
#define LOCAL_EN_PASSANT_PAWN_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "controllers/EnPassantPawnController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalEnPassantPawnController : public LocalPlacementController, public EnPassantPawnController
    {
    public:
        LocalEnPassantPawnController(Game &game);

        bool isApplicable();

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override;
    };
}

#endif

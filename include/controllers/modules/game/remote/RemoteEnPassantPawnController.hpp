#ifndef REMOTE_EN_PASSANT_PAWN_CONTROLLER_HPP
#define REMOTE_EN_PASSANT_PAWN_CONTROLLER_HPP

#include "controllers/modules/game/EnPassantPawnController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteEnPassantPawnController : public EnPassantPawnController, public RemoteOperationController
    {
    public:
        RemoteEnPassantPawnController(Game *game);

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override
    };
}

#endif

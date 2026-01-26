#ifndef REMOTE_CASTLING_MOVES_CONTROLLER_HPP
#define REMOTE_CASTLING_MOVES_CONTROLLER_HPP

#include "controllers/modules/game/CastlingMovesController.hpp"
#include "RemoteOperationController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteCastlingMovesController : public CastlingMovesController, public RemoteOperationController
    {
    public:
        RemoteCastlingMovesController(Game *game) : RemoteOperationController(game) {}

        void accept(SpecialMovementsControllerVisitor &specialMovementsControllerVisitor) override
    };
}

#endif

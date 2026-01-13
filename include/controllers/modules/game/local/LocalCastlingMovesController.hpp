#ifndef LOCAL_CASTLING_MOVES_CONTROLLER_HPP
#define LOCAL_CASTLING_MOVES_CONTROLLER_HPP

#include "controllers/modules/game/CastlingMovesController.hpp"
#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "models/Game.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"

namespace controllers::modules::game
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers::modules::game::local
{
    class LocalCastlingMovesController : public LocalPlacementController, public CastlingMovesController
    {
    public:
        LocalCastlingMovesController(Game &game);

        void accept(SpecialMovementsControllerVisitor &operationControllerVisitor) override;
        void accept(OperationControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

#ifndef LOCAL_CASTLING_MOVES_CONTROLLER_HPP
#define LOCAL_CASTLING_MOVES_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "models/modules/game/Game.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"
#include "controllers/modules/game/CastlingMovesController.hpp"

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

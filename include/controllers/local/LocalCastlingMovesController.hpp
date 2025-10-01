#ifndef LOCAL_CASTLING_MOVES_CONTROLLER_HPP
#define LOCAL_CASTLING_MOVES_CONTROLLER_HPP

#include "controllers/CastlingMovesController.hpp"
#include "LocalOperationController.hpp"
#include "LocalPlacementController.hpp"
#include "models/Game.hpp"

namespace controllers
{
    class SpecialMovementsControllerVisitor;
}

namespace controllers::local
{
    class LocalCastlingMovesController : public LocalPlacementController, public CastlingMovesController
    {
    public:
        LocalCastlingMovesController(Game &game);

        void accept(SpecialMovementsControllerVisitor &operationControllerVisitor) override;
    };
}

#endif

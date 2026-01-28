#ifndef PUT_PIECE_CONTROLLER_HPP
#define PUT_PIECE_CONTROLLER_HPP

#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game
{
    class PutPieceController : virtual public OperationController
    {
    public:
        virtual ~PutPieceController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

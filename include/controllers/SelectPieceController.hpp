#ifndef SELECT_PIECE_CONTROLLER_HPP
#define SELECT_PIECE_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

namespace controllers
{
    class SelectPieceController : public OperationController
    {
    public:
        virtual ~SelectPieceController() = default;

        virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
    };
}

#endif

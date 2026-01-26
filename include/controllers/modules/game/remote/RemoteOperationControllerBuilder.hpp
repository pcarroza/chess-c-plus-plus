#ifndef REMOTE_OPERATION_CONTROLLER_BUILDER_HPP
#define REMOTE_OPERATION_CONTROLLER_BUILDER_HPP

#include "RemoteStartController.hpp"
#include "RemotePlacementController.hpp"
#include "RemotePutPieceController.hpp"

namespace controllers::modules::game::remote
{
    class RemoteOperationControllerBuilder : public OperationControllerVisitor
    {
    public:
        RemoteOperationControllerBuilder(Game *game);

        void visit(StartController *startController) override;

        void visit(PlacementController *placementController) override;

        void visit(PutPieceController *putPieceController);

    };
}

#endif
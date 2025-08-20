#ifndef OPERATION_CONTROLLER_VISITOR_HPP
#define OPERATION_CONTROLLER_VISITOR_HPP

namespace controllers
{
    class StartController;

    class ContinueController;

    class PlacementController;

}

namespace controllers
{
    class OperationControllerVisitor
    {

    public:
        virtual ~OperationControllerVisitor() = default;

        virtual void visit(StartController *startController) = 0;

        virtual void visit(ContinueController *continueController) = 0;

        virtual void visit(PlacementController *placementController) = 0;
    };
}

#endif

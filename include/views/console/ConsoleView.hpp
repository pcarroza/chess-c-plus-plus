#ifndef CONSOLE_VIEW_HPP
#define CONSOLE_VIEW_HPP

#include "./View.hpp"
#include "controllers/OperationController.hpp"
#include "controllers/OperationControllerVisitor.hpp"
#include "controllers/ContinueController.hpp"
#include "controllers/PlacementController.hpp"
#include "controllers/StartController.hpp"
#include "ContinueView.hpp"
#include "StartView.hpp"
#include "GameView.hpp"

#include <memory>

namespace controllers
{
    class OperationController;

    class PlacementController;

    class ContinueController;

    class StartController;
}

namespace views::console
{
    class StartView;

    class GameView;

    class ContinueView;
}

using controllers::ContinueController;
using controllers::OperationController;
using controllers::OperationControllerVisitor;
using controllers::PlacementController;
using controllers::StartController;

namespace views::console
{
    class ConsoleView : public OperationControllerVisitor, public View
    {
    public:
        ConsoleView();

        ~ConsoleView();

        void interact(OperationController *operationController) override;

        void visit(StartController *startController) override;

        void visit(ContinueController *continueController) override;

        void visit(PlacementController *placementController) override;

    private:
        StartView *startView;

        GameView *gameView;

        ContinueView *continueView;
    };
}

#endif

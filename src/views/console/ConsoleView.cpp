#include "views/console/ConsoleView.hpp"

namespace views::console
{
    ConsoleView::ConsoleView()
        : startView(new StartView()),
          gameView(new GameView()),
          continueView(new ContinueView())
    {
    }

    ConsoleView::~ConsoleView()
    {
        delete startView;
        delete gameView;
        delete continueView;
    }

    void ConsoleView::interact(OperationController *operationController)
    {
        operationController->accept(*this);
    }

    void ConsoleView::visit(StartController *startController)
    {
        startView->interact(startController);
    }

    void ConsoleView::visit(PlacementController *placementController)
    {
        gameView->interact(placementController);
    }

    void ConsoleView::visit(ContinueController *continueController)
    {
        continueView->interact(continueController);
    }
}

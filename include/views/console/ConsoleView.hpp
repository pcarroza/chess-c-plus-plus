#ifndef CONSOLE_VIEW_HPP
#define CONSOLE_VIEW_HPP

#include "controllers/modules/game/OperationController.hpp"
#include "controllers/modules/game/OperationControllerVisitor.hpp"
#include "controllers/modules/game/ContinueController.hpp"
#include "controllers/modules/game/PlacementController.hpp"
#include "controllers/modules/game/StartController.hpp"
#include "ContinueView.hpp"
#include "StartView.hpp"
#include "GameView.hpp"
#include "./View.hpp"

#include <memory>

namespace views::console
{
    class StartView;
    class GameView;
    class ContinueView;
}

using controllers::modules::game::ContinueController;
using controllers::modules::game::OperationController;
using controllers::modules::game::OperationControllerVisitor;
using controllers::modules::game::PlacementController;
using controllers::modules::game::StartController;

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

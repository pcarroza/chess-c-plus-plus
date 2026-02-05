#include "views/modules/console/modules/game/StartView.hpp"
#include "controllers/modules/game/StartController.hpp"
#include <iostream>

namespace views::modules::console::modules::game
{
    StartView::StartView()
    {
    }

    StartView::~StartView()
    {
    }

    void StartView::interact(StartController *startController)
    {
        startController->start(2);
    }
}

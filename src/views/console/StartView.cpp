#include "views/console/StartView.hpp"
#include "controllers/StartController.hpp"
#include <iostream>

namespace views::console
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

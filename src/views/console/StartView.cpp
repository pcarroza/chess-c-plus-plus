#include "views/console/StartView.hpp"
#include "controllers/StartController.hpp"

namespace views::console
{
    StartView::StartView()
    {
    }

    StartView::~StartView()
    {
    }

    void StartView::interact(controllers::StartController *startController)
    {
        startController->start(2);
        delete startController;
    }
}

#include "Chess.hpp"
#include "controllers/modules/game/OperationController.hpp"

Chess::Chess() : logic(nullptr), view(nullptr)
{
}

Chess::~Chess()
{
    delete logic;
    delete view;
}

void Chess::run()
{
    if (logic == nullptr)
    {
        logic = getLogic();
    }

    if (view == nullptr)
    {
        view = getView();
    }

    controllers::modules::game::OperationController *controller;
    do
    {
        controller = logic->getController();
        if (controller != nullptr)
        {
            view->interact(controller);
        }
    } while (controller != nullptr);
}

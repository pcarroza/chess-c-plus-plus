#include "Chess.hpp"

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
}

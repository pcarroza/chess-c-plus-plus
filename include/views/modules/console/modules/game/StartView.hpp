#ifndef START_VIEW_HPP
#define START_VIEW_HPP

#include <iostream>

#include "controllers/modules/game/StartController.hpp"

using controllers::modules::game::StartController;

namespace views::modules::console::modules::game
{
    class StartView
    {
    public:
        StartView();

        ~StartView();

        void interact(StartController *startController);
    };
}

#endif

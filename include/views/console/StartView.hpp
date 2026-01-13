#ifndef START_VIEW_HPP
#define START_VIEW_HPP

#include <iostream>

#include "../../controllers/modules/game/StartController.hpp"

using controllers::modules::game::StartController;

namespace views::console
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

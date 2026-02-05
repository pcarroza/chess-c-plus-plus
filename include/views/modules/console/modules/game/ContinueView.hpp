#ifndef CONTINUE_VIEW_HPP
#define CONTINUE_VIEW_HPP

#include "controllers/modules/game/ContinueController.hpp"

using controllers::modules::game::ContinueController;

namespace views::modules::console::modules::game
{

    class ContinueView
    {
    public:
        ContinueView();

        ~ContinueView();

        void interact(ContinueController *continueController);
    };
}

#endif

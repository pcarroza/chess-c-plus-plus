#ifndef CONTINUE_VIEW_HPP
#define CONTINUE_VIEW_HPP

#include "../../controllers/modules/game/ContinueController.hpp"

using controllers::modules::game::ContinueController;

namespace views::console
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

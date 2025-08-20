#ifndef CONTINUE_VIEW_HPP
#define CONTINUE_VIEW_HPP

#include "../../controllers/ContinueController.hpp"

namespace controllers
{
    class ContinueController;
}

using controllers::ContinueController;

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

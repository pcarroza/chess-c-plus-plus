#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

#include "../../controllers/PlacementController.hpp"

namespace controllers
{
    class PlacementController;
}

using controllers::PlacementController;

namespace views::console
{
    class GameView
    {
    public:
        GameView();

        ~GameView();

        void interact(PlacementController *placementController);
    };
}

#endif

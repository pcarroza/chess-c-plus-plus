#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

#include "controllers/modules/game/PlacementController.hpp"

namespace controllers::modules::game
{
    class PlacementController;
}

using controllers::modules::game::PlacementController;

namespace views::modules::console::modules::game
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

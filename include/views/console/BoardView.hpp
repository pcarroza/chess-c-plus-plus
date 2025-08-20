#ifndef BOARD_VIEW_HPP
#define BOARD_VIEW_HPP

#include "controllers/PlacementController.hpp"

using controllers::PlacementController;

namespace views::console
{
    class PlacementController;

    class BoardView
    {
    public:
        BoardView();

        ~BoardView();

        void interact(PlacementController *placementController);
    };
}

#endif

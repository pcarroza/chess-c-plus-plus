#ifndef LOCAL_PLACEMENT_CONTROLLER_BUILDER_HPP
#define LOCAL_PLACEMENT_CONTROLLER_BUILDER_HPP

#include <vector>
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalPlacementController;

    class LocalCoordinateController;
}

namespace controllers::local
{
    class LocalPlacementControllerBuilder
    {
    public:
        LocalPlacementControllerBuilder(Game &game);

        virtual ~LocalPlacementControllerBuilder();

        virtual void build() = 0;

        void build(std::vector<LocalCoordinateController *> localCoordinateControllers);

        LocalPlacementController *getPlacementController();

    private:
        Game &game;

        std::vector<LocalPlacementController *> controllers;
    };
}

#endif

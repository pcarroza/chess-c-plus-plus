#ifndef LOCAL_PLACEMENT_CONTROLLER_BUILDER_HPP
#define LOCAL_PLACEMENT_CONTROLLER_BUILDER_HPP

#include <memory>
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
        
        void build(std::vector<std::unique_ptr<LocalCoordinateController>> localCoordinateControllers);

        LocalPlacementController *getPlacementController();
        
        Game &getGame();

    private:
        Game &game;

        std::vector<std::unique_ptr<LocalCoordinateController>> localCoordinateControllers;
        
        std::vector<std::unique_ptr<LocalPlacementController>> controllers;
    };
}

#endif
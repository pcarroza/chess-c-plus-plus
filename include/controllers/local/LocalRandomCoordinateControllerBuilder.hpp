#ifndef LOCAL_RANDOM_COORDINATE_CONTROLLER_BUILDER_HPP
#define LOCAL_RANDOM_COORDINATE_CONTROLLER_BUILDER_HPP

#include "LocalPlacementControllerBuilder.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalRandomCoordinateControllerBuilder : public LocalPlacementControllerBuilder
    {
    public:
        LocalRandomCoordinateControllerBuilder(Game &game);

        void build();
    };
}

#endif

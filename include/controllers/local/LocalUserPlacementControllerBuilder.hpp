#ifndef LOCAL_USER_PLACEMENT_CONTROLLER_BUILDER_HPP
#define LOCAL_USER_PLACEMENT_CONTROLLER_BUILDER_HPP

#include "LocalPlacementControllerBuilder.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalUserPlacementControllerBuilder : public LocalPlacementControllerBuilder
    {
    public:
        LocalUserPlacementControllerBuilder(Game &game);

        void build();
    };
}

#endif

#ifndef REMOTE_USER_PLACEMENT_CONTROLLER_BUILDER_HPP
#define REMOTE_USER_PLACEMENT_CONTROLLER_BUILDER_HPP

#include "RemoteUserPlacementControllerBuilder.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::remote
{
    class RemoteUserPlacementControllerBuilder
    {
    public:
        RemoteUserPlacementControllerBuilder(Game *game);
    };
}

#endif

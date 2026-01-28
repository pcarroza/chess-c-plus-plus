#ifndef REMOTE_CONTROLLER_HPP
#define REMOTE_CONTROLLER_HPP

#include "controllers/modules/game/OperationController.hpp"
#include "models/modules/game/Game.hpp"

using models::modules::game::Game;

namespace controllers::modules::game::remote
{
    class RemoteController : public OperationController
    {
    public:
        RemoteController(Game *game);

        virtual ~RemoteController() = default;

    protected:
        Game *game;
    };
}

#endif

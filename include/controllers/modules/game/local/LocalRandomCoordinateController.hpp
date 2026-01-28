#ifndef LOCAL_RANDOM_COORDINATE_CONTROLLER_HPP
#define LOCAL_RANDOM_COORDINATE_CONTROLLER_HPP

#include "LocalCoordinateController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local
{
    class LocalRandomCoordinateController : public LocalCoordinateController
    {
    public:
        LocalRandomCoordinateController(Game &game);
    };
}

#endif

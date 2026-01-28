#ifndef LOCAL_COORDINATE_CONTROLLER_HPP
#define LOCAL_COORDINATE_CONTROLLER_HPP

#include "LocalController.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game::local
{
    class LocalCoordinateController : public LocalController
    {
    public:
        LocalCoordinateController(Game &game);

        virtual ~LocalCoordinateController() = default; 
    };
}

#endif

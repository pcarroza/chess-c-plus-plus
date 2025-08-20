#ifndef LOCAL_USER_COORDINATE_CONTROLLER_HPP
#define LOCAL_USER_COORDINATE_CONTROLLER_HPP

#include "LocalCoordinateController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalUserCoordinateController : public LocalCoordinateController
    {
    public:
        LocalUserCoordinateController(Game &game);
    };
}

#endif

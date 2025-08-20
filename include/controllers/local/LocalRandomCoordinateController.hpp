#ifndef LOCAL_RANDOM_COORDINATE_CONTROLLER_HPP
#define LOCAL_RANDOM_COORDINATE_CONTROLLER_HPP

#include "LocalCoordinateController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalRandomCoordinateController : public LocalCoordinateController
    {
    public:
        LocalRandomCoordinateController(Game &game);
    };
}

#endif

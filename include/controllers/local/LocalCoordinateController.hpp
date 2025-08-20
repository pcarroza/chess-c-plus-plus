#ifndef LOCAL_COORDINATE_CONTROLLER_HPP
#define LOCAL_COORDINATE_CONTROLLER_HPP

#include "LocalController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalCoordinateController : public LocalController
    {
    public:
        LocalCoordinateController(Game &game);

        virtual ~LocalCoordinateController() = default; 
    };
}

#endif

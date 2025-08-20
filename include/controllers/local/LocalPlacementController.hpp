#ifndef LOCAL_PLACEMENT_CONTROLLER_HPP
#define LOCAL_PLACEMENT_CONTROLLER_HPP

#include "LocalOperationController.hpp"
#include "controllers/PlacementController.hpp"
#include "models/Game.hpp"

namespace controllers::local
{
    class LocalPlacementController : public LocalOperationController, public PlacementController
    {
    public:
        LocalPlacementController(Game &game);

        virtual ~LocalPlacementController() = default;
    };
}

#endif

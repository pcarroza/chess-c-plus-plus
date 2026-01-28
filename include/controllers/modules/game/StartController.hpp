#ifndef START_CONTROLLER_HPP
#define START_CONTROLLER_HPP

#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"
#include "models/modules/game/Game.hpp"

namespace controllers::modules::game
{
    class StartController : virtual public OperationController
    {
    public:
        virtual ~StartController() = default;

        virtual void start(int users) = 0;
    };
}

#endif

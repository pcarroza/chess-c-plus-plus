#ifndef START_CONTROLLER_HPP
#define START_CONTROLLER_HPP

#include "models/Game.hpp"
#include "OperationController.hpp"
#include "OperationControllerVisitor.hpp"

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

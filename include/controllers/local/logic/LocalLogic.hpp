#ifndef LOCAL_LOGIC_HPP
#define LOCAL_LOGIC_HPP

#include "controllers/local/LocalOperationController.hpp"
#include "models/LogicObserver.hpp"
#include "Logic.hpp"

namespace controllers::local
{
    class LocalOperationController;
    class LocalOperationControllerBuilder;
}

namespace controllers::local::logic
{
    class State;
    class StateBuilder;
}

class Game;

using controllers::local::LocalOperationController;
using models::LogicObserver;

namespace controllers::local::logic
{
    class LocalLogic : public Logic, public LogicObserver
    {
    public:
        LocalLogic();

        ~LocalLogic();

        void initialize() override;

        void begin() override;

        void finalize() override;

        void end() override;

        LocalOperationController *getController() override;

    private:
        Game *game;

        State *state;

        StateBuilder *stateBuilder;
        
        LocalOperationControllerBuilder *builder;
    };
}

#endif
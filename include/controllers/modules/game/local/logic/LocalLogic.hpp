#ifndef LOCAL_LOGIC_HPP
#define LOCAL_LOGIC_HPP

#include "controllers/modules/game/local/LocalOperationController.hpp"
#include "models/modules/game/LogicObserver.hpp"
#include "Logic.hpp"

namespace controllers::modules::game::local
{
    class LocalOperationController;
    class LocalOperationControllerBuilder;
}

namespace controllers::modules::game::local::logic
{
    class State;
    class StateBuilder;
}

class Game;

using controllers::modules::game::local::LocalOperationController;
using models::modules::game::LogicObserver;

namespace controllers::modules::game::local::logic
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
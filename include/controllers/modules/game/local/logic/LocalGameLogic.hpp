#ifndef LOCAL_GAME_LOGIC_HPP
#define LOCAL_GAME_LOGIC_HPP

#include "controllers/modules/game/local/LocalOperationController.hpp"
#include "models/modules/game/LogicObserver.hpp"
#include "Logic.hpp"

using controllers::modules::game::local::LocalOperationController;
using models::modules::game::Game;
using models::modules::game::LogicObserver;

namespace controllers::modules::game::local
{
    class LocalOperationController;
    class LocalOperationControllerBuilder;
}

namespace controllers::modules::game::local::logic
{
    class GameState;
    class GameStateBuilder;
}

namespace models::modules::game
{
    class Game;
}

namespace controllers::modules::game::local::logic
{
    class LocalGameLogic : public Logic, public LogicObserver
    {
    public:
        LocalGameLogic();

        ~LocalGameLogic();

        void initialize() override;

        void begin() override;

        void finalize() override;

        void end() override;

        void save() override;

        void resume() override;

        LocalOperationController *getController() override;

    private:
        Game *game;

        GameState *state;

        GameStateBuilder *gameStateBuilder;

        LocalOperationControllerBuilder *builder;
    };
}

#endif
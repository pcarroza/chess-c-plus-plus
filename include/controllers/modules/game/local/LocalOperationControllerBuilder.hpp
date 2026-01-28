#ifndef LOCAL_OPERATION_CONTROLLER_BUILDER_HPP
#define LOCAL_OPERATION_CONTROLLER_BUILDER_HPP

#include <list>
#include <memory>

#include "models/modules/game/Game.hpp"

using models::modules::game::Game;

namespace controllers::modules::game::local
{
    class LocalStartController;
    class LocalOperationController;
    class LocalPlacementControllerBuilder;
    class LocalContinueController;
}

namespace controllers::modules::game::local
{
    class LocalOperationControllerBuilder
    {
    public:
        LocalOperationControllerBuilder(Game &game);

        ~LocalOperationControllerBuilder();

        void build();

        void build(int users);

        LocalStartController *getStartController();

        LocalOperationController *getPlacementController();

        LocalContinueController *getContinueController();

    private:
        Game &game;

        unsigned int builderCursor;

        std::unique_ptr<LocalStartController> localStartController;

        std::list<std::shared_ptr<LocalPlacementControllerBuilder>> builders;

        std::unique_ptr<LocalContinueController> localContinueController;
    };
}

#endif

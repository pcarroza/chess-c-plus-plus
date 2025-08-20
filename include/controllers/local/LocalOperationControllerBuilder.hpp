#ifndef LOCAL_OPERATION_CONTROLLER_BUILDER_HPP
#define LOCAL_OPERATION_CONTROLLER_BUILDER_HPP

#include <vector>

#include "models/Game.hpp"

namespace controllers::local
{
    class LocalStartController;
    class LocalOperationController;
    class LocalPlacementControllerBuilder;
    class LocalContinueController;
}

namespace controllers::local
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

        LocalStartController *localStartController;

        std::vector<std::shared_ptr<LocalPlacementControllerBuilder>> builders;

        LocalContinueController *localContinueController;
    };
}

#endif

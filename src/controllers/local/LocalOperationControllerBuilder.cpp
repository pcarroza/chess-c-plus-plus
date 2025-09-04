#include "controllers/local/LocalOperationControllerBuilder.hpp"
#include "controllers/local/LocalStartController.hpp"
#include "controllers/local/LocalContinueController.hpp"
#include "controllers/local/LocalPlacementController.hpp"
#include "controllers/local/LocalSelectPieceController.hpp"
#include "controllers/local/LocalPlacementControllerBuilder.hpp"
#include "controllers/local/LocalUserPlacementControllerBuilder.hpp"
#include "controllers/local/LocalRandomCoordinateControllerBuilder.hpp"

namespace controllers::local
{
    LocalOperationControllerBuilder::LocalOperationControllerBuilder(Game &game) : game(game), builderCursor(0)
    {
    }

    LocalOperationControllerBuilder::~LocalOperationControllerBuilder()
    {
    }

    void LocalOperationControllerBuilder::build()
    {
        localStartController = std::make_unique<LocalStartController>(game, this);
        localContinueController = std::make_unique<LocalContinueController>(game);
    }

    void LocalOperationControllerBuilder::build(int users)
    {
        for (int i = 0; i < users; ++i)
        {
            this->builders.push_back(std::make_shared<LocalUserPlacementControllerBuilder>(game));
        }
        for (int i = 0; i < (2 - users); ++i)
        {
            this->builders.push_back(std::make_shared<LocalRandomCoordinateControllerBuilder>(game));
        }
        for (const auto &builder : builders)
        {
            builder->build();
        }
    }

    LocalStartController *LocalOperationControllerBuilder::getStartController()
    {
        return localStartController.get();
    }

    LocalOperationController *LocalOperationControllerBuilder::getPlacementController()
    {
        auto it = builders.begin();
        std::advance(it, this->builderCursor);
        LocalOperationController *controller = (*it)->getPlacementController();
        this->builderCursor = (this->builderCursor + 1) % builders.size();
        return controller;
    }

    LocalContinueController *LocalOperationControllerBuilder::getContinueController()
    {
        return localContinueController.get();
    }
}

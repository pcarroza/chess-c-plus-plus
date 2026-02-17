#include "models/modules/game/pieces/rules/MovementRulesGeneratorFactory.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGenerator.hpp"
#include "models/modules/game/pieces/rules/GeneratorRegistry.hpp"

namespace models::modules::game::pieces::rules
{
    MovementRulesGeneratorFactory::MovementRulesGeneratorFactory()
    {
        GeneratorRegistry::registerAll(*this);
    }

    MovementRulesGeneratorFactory::~MovementRulesGeneratorFactory()
    {
        releaseAll();
    }

    MovementRulesGeneratorFactory &MovementRulesGeneratorFactory::getInstance()
    {
        static MovementRulesGeneratorFactory instance;
        return instance;
    }

    void MovementRulesGeneratorFactory::releaseAll()
    {
        std::lock_guard<std::mutex> lock(mutex);

        for (auto &pair : generatorCache)
        {
            delete pair.second;
        }

        generatorCache.clear();
    }
}
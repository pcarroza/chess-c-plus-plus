#ifndef MOVEMENT_RULES_GENERATOR_FACTORY_HPP
#define MOVEMENT_RULES_GENERATOR_FACTORY_HPP

#include <memory>
#include <unordered_map>
#include <functional>
#include <mutex>
#include <typeindex>

namespace models::modules::game::pieces::rules
{
    class MovementRulesBaseGenerator;
}

namespace models::modules::game::pieces::rules
{
    class MovementRulesGeneratorFactory
    {
    public:
        static MovementRulesGeneratorFactory &getInstance();

        template <typename PieceType, typename GeneratorType>
        void registerGenerator();

        template <typename PieceType>
        MovementRulesBaseGenerator *getGenerator();

        void releaseAll();

        MovementRulesGeneratorFactory(const MovementRulesGeneratorFactory &) = delete;

        MovementRulesGeneratorFactory &operator=(const MovementRulesGeneratorFactory &) = delete;

    private:
        MovementRulesGeneratorFactory();

        ~MovementRulesGeneratorFactory();

        using FactoryFunction = std::function<MovementRulesBaseGenerator *()>;

        std::unordered_map<std::type_index, FactoryFunction> factoryMap;

        std::unordered_map<std::type_index, MovementRulesBaseGenerator *> generatorCache;

        std::mutex mutex;

        friend class GeneratorRegistry;
    };
}

namespace models::modules::game::pieces::rules
{
    template <typename PieceType, typename GeneratorType>
    void MovementRulesGeneratorFactory::registerGenerator()
    {
        std::lock_guard<std::mutex> lock(mutex);

        std::type_index pieceTypeIndex(typeid(PieceType));

        factoryMap[pieceTypeIndex] = []() -> MovementRulesBaseGenerator *
        {
            return new GeneratorType();
        };
    }

    template <typename PieceType>
    MovementRulesBaseGenerator *MovementRulesGeneratorFactory::getGenerator()
    {
        std::lock_guard<std::mutex> lock(mutex);

        std::type_index pieceTypeIndex(typeid(PieceType));

        auto cacheIt = generatorCache.find(pieceTypeIndex);
        if (cacheIt != generatorCache.end())
        {
            return cacheIt->second;
        }

        auto factoryIt = factoryMap.find(pieceTypeIndex);
        if (factoryIt == factoryMap.end())
        {
            return nullptr;
        }

        MovementRulesBaseGenerator *generator = factoryIt->second();
        generatorCache[pieceTypeIndex] = generator;

        return generator;
    }
}

#endif
#ifndef GENERATOR_REGISTRY_HPP
#define GENERATOR_REGISTRY_HPP

namespace models::modules::game::pieces::rules
{
    class MovementRulesGeneratorFactory;
}

namespace models::modules::game::pieces::rules
{
    class GeneratorRegistry
    {
    public:
        static void registerAll(MovementRulesGeneratorFactory &factory);

    private:
        GeneratorRegistry() = delete;
    };
}

#endif
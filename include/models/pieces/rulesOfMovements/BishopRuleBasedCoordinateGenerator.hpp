#ifndef BISHOP_RULE_BASED_COORDINATE_GENERATOR_HPP
#define BISHOP_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "RuleBasedCoordinateGenerator.hpp"

namespace models::pieces::rulesOfMovements
{
    class BishopRuleBasedCoordinateGenerator : public MovementRulesBaseGeneratorGenerator
    {
    public:
        BishopRuleBasedCoordinateGenerator(Piece &piece);

        void generate() override;
    };
}

#endif

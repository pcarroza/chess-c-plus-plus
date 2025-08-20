#ifndef ROOK_RULE_BASED_COORDINATE_GENERATOR_HPP
#define ROOK_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "RuleBasedCoordinateGenerator.hpp"

namespace models::pieces::rulesOfMovements
{
    class RookRuleBasedCoordinateGenerator : public MovementRulesBaseGeneratorGenerator
    {
    public:
        RookRuleBasedCoordinateGenerator(Piece &piece);

        void generate() override;
    };
}

#endif

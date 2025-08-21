#ifndef QUEEN_RULE_BASED_COORDINATE_GENERATOR_HPP
#define QUEEN_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "RuleBasedCoordinateGenerator.hpp"

namespace models::pieces::rulesOfMovements
{
    class QueenRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        QueenRuleBasedCoordinateGenerator(Piece &piece);

        void generate() override;
    };
}

#endif

#ifndef PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP
#define PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "RuleBasedCoordinateGenerator.hpp"

namespace models::pieces::rulesOfMovements
{
    class PawnRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        PawnRuleBasedCoordinateGenerator(Piece &piece);

        void generate() override;
    };
}

#endif

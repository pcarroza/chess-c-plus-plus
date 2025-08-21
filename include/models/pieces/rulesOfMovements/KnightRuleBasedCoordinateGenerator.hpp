#ifndef KNIGHT_RULE_BASED_COORDINATE_GENERATOR_HPP
#define KNIGHT_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "MovementRulesBaseGenerator.hpp"
#include "../../../common/validators/ValidatorLimitsBoard.hpp"

namespace common::validators
{
    class ValidatorLimitsBoard;
}

using common::validators::ValidatorLimitsBoard;

namespace models::pieces::rulesOfMovements
{
    class KnightRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        KnightRuleBasedCoordinateGenerator(Piece *piece);

        void generate() override;
    };
}

#endif

#ifndef KING_RULE_BASED_COORDINATE_GENERATOR_HPP
#define KING_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "RuleBasedCoordinateGenerator.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

#include <memory>

namespace common::validators
{
    class ValidatorLimitsBoard;
}

using common::validators::ValidatorLimitsBoard;

namespace models::pieces::rulesOfMovements
{
    class KingRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        KingRuleBasedCoordinateGenerator(Piece *piece);

        void generate() override;
    };
}

#endif

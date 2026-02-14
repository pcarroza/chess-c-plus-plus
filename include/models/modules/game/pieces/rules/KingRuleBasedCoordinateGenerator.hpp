#ifndef KING_RULE_BASED_COORDINATE_GENERATOR_HPP
#define KING_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "MovementRulesBaseGenerator.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"

#include <memory>

namespace common::validators
{
    class ValidatorLimitsBoard;
}

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    class KingRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        KingRuleBasedCoordinateGenerator();

        void generate(const Piece& piece) override;
    };
}

#endif

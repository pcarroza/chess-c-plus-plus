// ...existing code...
#ifndef ENPASSANTPAWNSPECIALRULEGENERATOR_HPP
#define ENPASSANTPAWNSPECIALRULEGENERATOR_HPP

#include "common/validators/ValidatorLimitsBoard.hpp"
#include "SpecialMovesRulesGenerator.hpp"
#include "models/modules/game/Player.hpp"

#include <vector>
#include <cassert>

namespace common::validators
{
    class ValidatorLimitsBoard;
}

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::special
{
    class InStepSpecialRuleGenerator : public SpecialMovesRulesGenerator
    {
    public:
        InStepSpecialRuleGenerator(Piece *piece);

        void generate() override;
    };
}

#endif

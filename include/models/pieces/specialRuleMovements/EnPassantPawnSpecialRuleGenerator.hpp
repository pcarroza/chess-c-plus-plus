#ifndef ENPASSANTPAWNSPECIALRULEGENERATOR_HPP
#define ENPASSANTPAWNSPECIALRULEGENERATOR_HPP

#include "models/pieces/specialRuleMovements/SpecialMovesRulesGenerator.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/pieces/Pawn.hpp"
#include "models/Player.hpp"

#include <vector>
#include <cassert>

namespace common::validators
{
    class ValidatorLimitsBoard;
}

using common::validators::ValidatorLimitsBoard;

namespace models::pieces::specialRuleMovements
{
    class EnPassantPawnSpecialRuleGenerator : public SpecialMovesRulesGenerator
    {
    public:
        EnPassantPawnSpecialRuleGenerator(Piece *piece);

        void generate() override;
    };
}

#endif

#ifndef PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP
#define PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "common/validators/ValidatorLimitsBoard.hpp"
#include "MovementRulesBaseGenerator.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/Player.hpp"

#include <vector>
#include <cassert>

namespace common::validators
{
    class ValidatorLimitsBoard;
}

using common::validators::ValidatorLimitsBoard;

namespace models::modules::game::pieces::rules
{
    class PawnRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        PawnRuleBasedCoordinateGenerator(Piece *piece);

        PawnRuleBasedCoordinateGenerator() = default;

        void set(Piece *piece) override;

        void generate() override;

    private:
        Pawn *pawn;
    };
}

#endif

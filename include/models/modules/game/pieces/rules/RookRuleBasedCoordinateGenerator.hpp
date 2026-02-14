#ifndef ROOK_RULE_BASED_COORDINATE_GENERATOR_HPP
#define ROOK_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "MovementRulesBaseGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    class RookRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        RookRuleBasedCoordinateGenerator();

        void generate(const Piece& piece) override;
    };
}

#endif

#ifndef BISHOP_RULE_BASED_COORDINATE_GENERATOR_HPP
#define BISHOP_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "MovementRulesBaseGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    class BishopRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        BishopRuleBasedCoordinateGenerator(Piece *piece);

        void generate() override;
    };
}

#endif

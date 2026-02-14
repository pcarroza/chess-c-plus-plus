#ifndef RULER_BASED_COORDINATE_GENERATOR_FACADE_HPP
#define RULER_BASED_COORDINATE_GENERATOR_FACADE_HPP

namespace models::modules::game::pieces::rules
{
    class MovementRulesBaseGenerator;
}

namespace models::modules::game::pieces
{
    class Piece;
}

using models::modules::game::pieces::Piece;
using models::modules::game::pieces::rules::MovementRulesBaseGenerator;

namespace models::modules::game::pieces::rules
{
    MovementRulesBaseGenerator *createBishopRuleBasedCoordinateGenerator();

    MovementRulesBaseGenerator *createKingRuleBasedCoordinateGenerator();

    MovementRulesBaseGenerator *createKnightRuleBasedCoordinateGenerator();

    MovementRulesBaseGenerator *createQueenRuleBasedCoordinateGenerator();

    MovementRulesBaseGenerator *createRookRuleBasedCoordinateGenerator();

    MovementRulesBaseGenerator *createPawnRuleBasedCoordinateGenerator();
}
#endif

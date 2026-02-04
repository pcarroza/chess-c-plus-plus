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
    MovementRulesBaseGenerator *createBishopRuleBasedCoordinateGenerator(Piece *piece);

    MovementRulesBaseGenerator *createKingRuleBasedCoordinateGenerator(Piece *piece);

    MovementRulesBaseGenerator *createKnightRuleBasedCoordinateGenerator(Piece *piece);

    MovementRulesBaseGenerator *createQueenRuleBasedCoordinateGenerator(Piece *piece);

    MovementRulesBaseGenerator *createRookRuleBasedCoordinateGenerator(Piece *piece);

    MovementRulesBaseGenerator *createPawnRuleBasedCoordinateGenerator(Piece *piece);
}
#endif

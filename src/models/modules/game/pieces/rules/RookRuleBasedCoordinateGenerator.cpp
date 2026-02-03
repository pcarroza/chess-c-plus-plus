#include "models/modules/game/pieces/rules/RookRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    RookRuleBasedCoordinateGenerator::RookRuleBasedCoordinateGenerator(Piece *piece)
        : MovementRulesBaseGenerator(piece)
    {
    }

    void RookRuleBasedCoordinateGenerator::generate()
    {
        possibleMoves.clear();
        possibleMoves = BuilderMovementStrategy::buildRookMovements(*piece);
    }
}

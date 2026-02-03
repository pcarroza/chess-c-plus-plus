#include "models/modules/game/pieces/rules/BishopRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    BishopRuleBasedCoordinateGenerator::BishopRuleBasedCoordinateGenerator(Piece *piece)
        : MovementRulesBaseGenerator(piece)
    {
    }

    void BishopRuleBasedCoordinateGenerator::generate()
    {
        possibleMoves.clear();
        possibleMoves = BuilderMovementStrategy::buildBishopMovements(*piece);
    }
}

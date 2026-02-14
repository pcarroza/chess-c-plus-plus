#include "models/modules/game/pieces/rules/BishopRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    BishopRuleBasedCoordinateGenerator::BishopRuleBasedCoordinateGenerator()
    {
    }

    void BishopRuleBasedCoordinateGenerator::generate(const Piece &piece)
    {
        possibleMoves.clear();
        possibleMoves = BuilderMovementStrategy::buildBishopMovements(piece);
    }
}

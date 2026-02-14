#include "models/modules/game/pieces/rules/RookRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    RookRuleBasedCoordinateGenerator::RookRuleBasedCoordinateGenerator()
    {
    }

    void RookRuleBasedCoordinateGenerator::generate(const Piece &piece)
    {
        possibleMoves.clear();
        possibleMoves = BuilderMovementStrategy::buildRookMovements(piece);
    }
}

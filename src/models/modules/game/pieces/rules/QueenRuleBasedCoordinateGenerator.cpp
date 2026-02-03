#include "models/modules/game/pieces/rules/QueenRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    QueenRuleBasedCoordinateGenerator::QueenRuleBasedCoordinateGenerator(Piece *piece)
        : MovementRulesBaseGenerator(piece)
    {
    }

    void QueenRuleBasedCoordinateGenerator::generate()
    {
        possibleMoves.clear();
        possibleMoves = BuilderMovementStrategy::buildQueenMovements(*piece);
    }
}

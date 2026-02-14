#include "models/modules/game/pieces/rules/QueenRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    QueenRuleBasedCoordinateGenerator::QueenRuleBasedCoordinateGenerator()
    {
    }

    void QueenRuleBasedCoordinateGenerator::generate(const Piece &piece)
    {
        possibleMoves.clear();
        possibleMoves = BuilderMovementStrategy::buildQueenMovements(piece);
    }
}

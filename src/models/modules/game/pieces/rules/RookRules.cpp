#include "models/modules/game/pieces/rules/RookRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    void RookRules::generate(const Piece &piece, std::vector<Coordinate> &movements) const
    {
        BuilderMovementStrategy::buildRookMovements(piece, movements);
    }
}

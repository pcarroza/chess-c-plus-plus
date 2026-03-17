#include "models/modules/game/pieces/rules/BishopRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using common::validators::ValidatorLimitsBoard;
using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    void BishopRules::generate(const Piece &piece, std::vector<Coordinate> &movements) const
    {
        BuilderMovementStrategy::buildBishopMovements(piece, movements);
    }

}

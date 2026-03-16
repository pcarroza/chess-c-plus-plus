#include "models/modules/game/pieces/rules/BishopRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using common::validators::ValidatorLimitsBoard;
using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    std::list<std::shared_ptr<Coordinate>> BishopRules::generate(const Piece &piece) const
    {
        return BuilderMovementStrategy::buildBishopMovements(piece);
    }

}

#include "models/modules/game/pieces/rules/RookRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    std::list<std::shared_ptr<Coordinate>> RookRules::generate(const Piece &piece) const
    {
        return BuilderMovementStrategy::buildRookMovements(piece);
    }
}

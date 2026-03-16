#include "models/modules/game/pieces/rules/QueenRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    std::list<std::shared_ptr<Coordinate>> QueenRules::generate(const Piece &piece) const
    {
        return BuilderMovementStrategy::buildQueenMovements(piece);
    }
}

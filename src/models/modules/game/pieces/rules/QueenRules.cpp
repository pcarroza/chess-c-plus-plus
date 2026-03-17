#include "models/modules/game/pieces/rules/QueenRules.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"

using namespace models::modules::game::pieces::rules::strategies;

namespace models::modules::game::pieces::rules
{
    void QueenRules::generate(const Piece &piece, std::vector<Coordinate> &movements) const
    {
        BuilderMovementStrategy::buildQueenMovements(piece, movements);
    }
}

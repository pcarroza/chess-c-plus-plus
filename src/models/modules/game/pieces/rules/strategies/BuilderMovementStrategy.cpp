#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/VerticalMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/HorizontalMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/InverseMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/DiagonalMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"

namespace models::modules::game::pieces::rules::strategies
{
    void BuilderMovementStrategy::buildRookMovements(const Piece &piece, std::vector<Coordinate> &movements)
    {
        VerticalMovementStrategy(piece).generate(movements);
        HorizontalMovementStrategy(piece).generate(movements);
    }

    void BuilderMovementStrategy::buildBishopMovements(const Piece &piece, std::vector<Coordinate> &movements)
    {
        InverseMovementStrategy(piece).generate(movements);
        DiagonalMovementStrategy(piece).generate(movements);
    }

    void BuilderMovementStrategy::buildQueenMovements(const Piece &piece, std::vector<Coordinate> &movements)
    {
        InverseMovementStrategy(piece).generate(movements);
        DiagonalMovementStrategy(piece).generate(movements);
        VerticalMovementStrategy(piece).generate(movements);
        HorizontalMovementStrategy(piece).generate(movements);
    }
}

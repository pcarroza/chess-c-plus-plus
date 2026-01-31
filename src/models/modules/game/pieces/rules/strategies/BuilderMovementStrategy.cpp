#include "models/modules/game/pieces/rules/strategies/BuilderMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/VerticalMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/HorizontalMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/InverseMovementStrategy.hpp"
#include "models/modules/game/pieces/rules/strategies/DiagonalMovementStrategy.hpp"
#include "models/modules/game/pieces/Piece.hpp"

namespace models::modules::game::pieces::rules::strategies
{
    std::list<std::shared_ptr<Coordinate>> BuilderMovementStrategy::buildRookMovements(Piece &piece)
    {
        std::list<std::shared_ptr<Coordinate>> movements;
        movements.splice(movements.end(), VerticalMovementStrategy(&piece).generate());
        movements.splice(movements.end(), HorizontalMovementStrategy(&piece).generate());
        return movements;
    }

    std::list<std::shared_ptr<Coordinate>> BuilderMovementStrategy::buildBishopMovements(Piece &piece)
    {
        std::list<std::shared_ptr<Coordinate>> movements;
        movements.splice(movements.end(), InverseMovementStrategy(&piece).generate());
        movements.splice(movements.end(), DiagonalMovementStrategy(&piece).generate());
        return movements;
    }

    std::list<std::shared_ptr<Coordinate>> BuilderMovementStrategy::buildQueenMovements(Piece &piece)
    {
        std::list<std::shared_ptr<Coordinate>> movements;
        movements.splice(movements.end(), InverseMovementStrategy(&piece).generate());
        movements.splice(movements.end(), DiagonalMovementStrategy(&piece).generate());
        movements.splice(movements.end(), VerticalMovementStrategy(&piece).generate());
        movements.splice(movements.end(), HorizontalMovementStrategy(&piece).generate());
        return movements;
    }
}

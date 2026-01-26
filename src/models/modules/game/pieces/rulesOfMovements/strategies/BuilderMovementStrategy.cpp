#include "models/pieces/rulesOfMovements/strategies/BuilderMovementStrategy.hpp"
#include "models/pieces/rulesOfMovements/strategies/VerticalMovementStrategy.hpp"
#include "models/pieces/rulesOfMovements/strategies/HorizontalMovementStrategy.hpp"
#include "models/pieces/rulesOfMovements/strategies/InverseMovementStrategy.hpp"
#include "models/pieces/rulesOfMovements/strategies/DiagonalMovementStrategy.hpp"
#include "models/pieces/Piece.hpp"

namespace models::pieces::rulesOfMovements::strategies
{
    std::list<std::shared_ptr<Coordinate>> BuilderMovementStrategy::buildRookMovements(Piece &piece)
    {
        std::list<std::shared_ptr<Coordinate>> movements;

        std::list<std::shared_ptr<MovementStrategy>> strategies = {
            std::shared_ptr<MovementStrategy>(new VerticalMovementStrategy(&piece)),
            std::shared_ptr<MovementStrategy>(new HorizontalMovementStrategy(&piece)),
        };
        for (const auto &strategy : strategies)
        {
            movements.splice(movements.end(), strategy->generate());
        }
        return movements;
    }

    std::list<std::shared_ptr<Coordinate>> BuilderMovementStrategy::buildBishopMovements(Piece &piece)
    {
        std::list<std::shared_ptr<Coordinate>> movements;

        std::list<std::shared_ptr<MovementStrategy>> strategies = {
            std::shared_ptr<MovementStrategy>(new InverseMovementStrategy(&piece)),
            std::shared_ptr<MovementStrategy>(new DiagonalMovementStrategy(&piece)),
        };
        for (const auto &strategy : strategies)
        {
            movements.splice(movements.end(), strategy->generate());
        }
        return movements;
    }

    std::list<std::shared_ptr<Coordinate>> BuilderMovementStrategy::buildQueenMovements(Piece &piece)
    {
        std::list<std::shared_ptr<Coordinate>> movements;

        std::list<std::shared_ptr<MovementStrategy>> strategies = {
            std::shared_ptr<MovementStrategy>(new InverseMovementStrategy(&piece)),
            std::shared_ptr<MovementStrategy>(new DiagonalMovementStrategy(&piece)),
            std::shared_ptr<MovementStrategy>(new VerticalMovementStrategy(&piece)),
            std::shared_ptr<MovementStrategy>(new HorizontalMovementStrategy(&piece)),
        };
        for (const auto &strategy : strategies)
        {
            movements.splice(movements.end(), strategy->generate());
        }
        return movements;
    }
}

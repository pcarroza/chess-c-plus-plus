#ifndef DIAGONAL_MOVEMENT_STRATEGY_HPP
#define DIAGONAL_MOVEMENT_STRATEGY_HPP

#include "models/pieces/rulesOfMovements/strategies/MovementStrategy.hpp"

namespace models::pieces::rulesOfMovements::strategies
{
    class DiagonalMovementStrategy : public MovementStrategy
    {
    public:
        DiagonalMovementStrategy() = delete;
        
        DiagonalMovementStrategy(Piece *piece);

        std::list<std::shared_ptr<Coordinate>> generate() override;

        Coordinate *getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

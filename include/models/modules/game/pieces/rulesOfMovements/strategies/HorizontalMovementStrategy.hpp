#ifndef HORIZONTAL_MOVEMENT_STRATEGY_HPP
#define HORIZONTAL_MOVEMENT_STRATEGY_HPP

#include "models/pieces/rulesOfMovements/strategies/MovementStrategy.hpp"

namespace models::pieces::rulesOfMovements::strategies
{
    class HorizontalMovementStrategy : public MovementStrategy
    {
    public:
        HorizontalMovementStrategy() = delete;

        HorizontalMovementStrategy(Piece *piece);

        std::list<std::shared_ptr<Coordinate>> generate() override;

        Coordinate *getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

#ifndef VERTICAL_MOVEMENT_STRATEGY_HPP
#define VERTICAL_MOVEMENT_STRATEGY_HPP

#include "MovementStrategy.hpp"

namespace models::pieces::rulesOfMovements::strategies
{
    class VerticalMovementStrategy : public MovementStrategy
    {
    public:
        VerticalMovementStrategy() = delete;

        VerticalMovementStrategy(Piece *piece);

        std::list<std::shared_ptr<Coordinate>> generate() override;

        Coordinate *getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

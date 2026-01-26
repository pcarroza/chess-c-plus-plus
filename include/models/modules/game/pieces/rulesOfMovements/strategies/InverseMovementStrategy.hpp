#ifndef INVERSE_MOVEMENT_STRATEGY_HPP
#define INVERSE_MOVEMENT_STRATEGY_HPP

#include "models/pieces/rulesOfMovements/strategies/MovementStrategy.hpp"

#include <list>
#include <memory>

namespace models::pieces::rulesOfMovements::strategies
{
    class InverseMovementStrategy : public MovementStrategy
    {
    public:
        InverseMovementStrategy(Piece *piece);

        InverseMovementStrategy() = delete;

        std::list<std::shared_ptr<Coordinate>> generate() override;

        Coordinate *getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif
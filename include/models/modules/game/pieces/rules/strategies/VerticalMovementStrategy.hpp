#ifndef VERTICAL_MOVEMENT_STRATEGY_HPP
#define VERTICAL_MOVEMENT_STRATEGY_HPP

#include "MovementStrategy.hpp"

namespace models::modules::game::pieces::rules::strategies
{
    class VerticalMovementStrategy : public MovementStrategy
    {
    public:
        VerticalMovementStrategy() = delete;

        VerticalMovementStrategy(const Piece &piece);

        std::list<std::shared_ptr<Coordinate>> generate() override;

        Coordinate *getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

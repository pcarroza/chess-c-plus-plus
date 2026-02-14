#ifndef HORIZONTAL_MOVEMENT_STRATEGY_HPP
#define HORIZONTAL_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"

namespace models::modules::game::pieces::rules::strategies
{
    class HorizontalMovementStrategy : public MovementStrategy
    {
    public:
        HorizontalMovementStrategy(const Piece &piece);

        HorizontalMovementStrategy() = delete;

        std::list<std::shared_ptr<Coordinate>> generate() override;

        Coordinate *getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

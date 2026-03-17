#ifndef HORIZONTAL_MOVEMENT_STRATEGY_HPP
#define HORIZONTAL_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"
#include <vector>

namespace models::modules::game::pieces::rules::strategies
{
    class HorizontalMovementStrategy : public MovementStrategy
    {
    public:
        HorizontalMovementStrategy(const Piece &piece);

        HorizontalMovementStrategy() = delete;

        void generate(std::vector<Coordinate> &movements) override;

        Coordinate getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

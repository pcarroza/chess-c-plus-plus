#ifndef VERTICAL_MOVEMENT_STRATEGY_HPP
#define VERTICAL_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"
#include <vector>

namespace models::modules::game::pieces::rules::strategies
{
    class VerticalMovementStrategy : public MovementStrategy
    {
    public:
        VerticalMovementStrategy() = delete;

        VerticalMovementStrategy(const Piece &piece);

        void generate(std::vector<Coordinate> &movements) override;

        Coordinate getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

#ifndef INVERSE_MOVEMENT_STRATEGY_HPP
#define INVERSE_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"
#include <vector>
#include <memory>

namespace models::modules::game::pieces::rules::strategies
{
    class InverseMovementStrategy : public MovementStrategy
    {
    public:
        InverseMovementStrategy(const Piece &piece);

        InverseMovementStrategy() = delete;

        void generate(std::vector<Coordinate> &movements) override;

        Coordinate getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

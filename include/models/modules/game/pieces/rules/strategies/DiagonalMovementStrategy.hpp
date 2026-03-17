#ifndef DIAGONAL_MOVEMENT_STRATEGY_HPP
#define DIAGONAL_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"
#include <vector>

namespace models::modules::game::pieces::rules::strategies
{
    class DiagonalMovementStrategy : public MovementStrategy
    {
    public:
        DiagonalMovementStrategy() = delete;
        
        DiagonalMovementStrategy(const Piece &piece);

        void generate(std::vector<Coordinate> &movements) override;

        Coordinate getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) override;
    };
}

#endif

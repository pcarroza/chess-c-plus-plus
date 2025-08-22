#ifndef DIAGONAL_MOVEMENT_STRATEGY_HPP
#define DIAGONAL_MOVEMENT_STRATEGY_HPP

#include "BaseMovementStrategy.hpp"

namespace models::pieces::rulesOfMovements::strategies
{
    class DiagonalMovementStrategy : public BaseMovementStrategy
    {
    public:
        DiagonalMovementStrategy() = delete;

        static std::list<std::shared_ptr<Coordinate>> generatePseudoCoordinates(Piece &piece);
    };
}

#endif

#ifndef INVERSE_MOVEMENT_STRATEGY_HPP
#define INVERSE_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"

#include <list>
#include <memory>

namespace models::modules::game::pieces::rules::strategies
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
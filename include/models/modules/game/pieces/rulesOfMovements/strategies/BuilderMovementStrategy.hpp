#ifndef BUILDER_MOVEMENT_STRATEGY_HPP
#define BUILDER_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rulesOfMovements/strategies/MovementStrategy.hpp"

#include <list>
#include <memory>

namespace models::modules::game::pieces::rulesOfMovements::strategies
{
    class BuilderMovementStrategy
    {
    public:
        BuilderMovementStrategy() = delete;

        static std::list<std::shared_ptr<Coordinate>> buildRookMovements(Piece &piece);

        static std::list<std::shared_ptr<Coordinate>> buildBishopMovements(Piece &piece);

        static std::list<std::shared_ptr<Coordinate>> buildQueenMovements(Piece &piece);
    };
}

#endif

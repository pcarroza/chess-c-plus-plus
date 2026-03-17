#ifndef BUILDER_MOVEMENT_STRATEGY_HPP
#define BUILDER_MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/rules/strategies/MovementStrategy.hpp"

#include <vector>
#include <memory>

namespace models::modules::game::pieces::rules::strategies
{
    class BuilderMovementStrategy
    {
    public:
        BuilderMovementStrategy() = delete;

        static void buildRookMovements(const Piece &piece, std::vector<Coordinate> &movements);

        static void buildBishopMovements(const Piece &piece, std::vector<Coordinate> &movements);

        static void buildQueenMovements(const Piece &piece, std::vector<Coordinate> &movements);
    };
}

#endif

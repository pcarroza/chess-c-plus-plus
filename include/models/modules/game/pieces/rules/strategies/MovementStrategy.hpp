#ifndef MOVEMENT_STRATEGY_HPP
#define MOVEMENT_STRATEGY_HPP

#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"

#include <vector>
#include <memory>

namespace models::modules::game::pieces
{
    class Piece;
    class Coordinate;
}

namespace models::modules::game::pieces::rules::strategies
{
    class MovementStrategy
    {
    public:
        MovementStrategy(const Piece &piece);

        virtual ~MovementStrategy() = default;

        virtual void generate(std::vector<Coordinate> &movements) = 0;

    protected:
        void generate(const Coordinate &vector, std::vector<Coordinate> &movements);

        virtual Coordinate getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) = 0;

    private:
        void generateRecursive(std::vector<Coordinate> &coordinates, const Coordinate &vector, int step);

    protected:
        const Piece &piece;
    };
}

#endif

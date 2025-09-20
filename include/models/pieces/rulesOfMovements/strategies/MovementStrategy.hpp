#ifndef MOVEMENT_STRATEGY_HPP
#define MOVEMENT_STRATEGY_HPP

#include "models/pieces/Piece.hpp"

#include <list>
#include <memory>

class Coordinate;
class Piece;

namespace models::pieces::rulesOfMovements::strategies
{
    class MovementStrategy
    {
    public:
        MovementStrategy(Piece *piece);

        virtual ~MovementStrategy() = default;

        std::list<std::shared_ptr<Coordinate>> generate(const Coordinate &coordinate);

        void generateRecursive(std::list<std::shared_ptr<Coordinate>> coordinates, const Coordinate &coordinate, int step);

        virtual Coordinate &getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) = 0;

    private:
        Piece *piece;
    };
}

#endif

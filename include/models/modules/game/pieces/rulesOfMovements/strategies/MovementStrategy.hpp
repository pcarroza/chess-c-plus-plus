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

        virtual std::list<std::shared_ptr<Coordinate>> generate() = 0;

    protected:

        std::list<std::shared_ptr<Coordinate>> generate(const Coordinate &vector);

        virtual Coordinate *getDisplacedCoordinateBy(int increment, const Coordinate &coordinate) = 0;

    private:
        void generateRecursive(std::list<std::shared_ptr<Coordinate>> &coordinates, const Coordinate &coordinate, int step);

    protected:
        Piece *piece;

    };
}

#endif


#ifndef MOVEMENT_STRATEGY_HPP
#define MOVEMENT_STRATEGY_HPP

#include <list>
#include <memory>

class Coordinate;
class Piece;

namespace models::pieces::rulesOfMovements::strategies
{
    class MovementStrategy
    {
    public:
        virtual ~MovementStrategy() = default;

        std::list<std::shared_ptr<Coordinate>> generate(Coordinate *coordinate);

        std::list<std::shared_ptr<Coordinate>> generateRecursive(std::list<std::shared_ptr<Coordinate>> coordinates, Coordinate vector, int step);
    };
}

#endif

#include "models/pieces/rulesOfMovements/strategies/MovementStrategy.hpp"
#include "models/pieces/Coordinate.hpp"
#include "MovementStrategy.hpp"

namespace models::pieces::rulesOfMovements::strategies
{

    std::list<std::shared_ptr<Coordinate>> MovementStrategy::generate(Coordinate *coordinate)
    {
        return std::list<std::shared_ptr<Coordinate>>();
    }

    std::list<std::shared_ptr<Coordinate>> MovementStrategy::generateRecursive(
        std::list<std::shared_ptr<Coordinate>> coordinates,
        Coordinate vector,
        int step)
    {
        if(|Validator) {}

        return std::list<std::shared_ptr<Coordinate>>();
    }
}

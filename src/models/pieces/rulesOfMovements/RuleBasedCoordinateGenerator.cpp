#include "models/pieces/rulesOfMovements/RuleBasedCoordinateGenerator.hpp"
#include "models/pieces/Piece.hpp"

namespace models::pieces::rulesOfMovements
{
    MovementRulesBaseGeneratorGenerator::MovementRulesBaseGeneratorGenerator(Piece &piece) : piece(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> MovementRulesBaseGeneratorGenerator::getValidMovements()
    {
        std::list<std::shared_ptr<Coordinate>> deepCopy;

        for (const auto &coordinate : possibleMoves)
        {
            deepCopy.push_back(std::make_shared<Coordinate>(*coordinate));
        }
        return possibleMoves;
    }

    bool MovementRulesBaseGeneratorGenerator::isMovementValid(const Coordinate &coordinate)
    {
        return isContained(coordinate);
    }

    bool MovementRulesBaseGeneratorGenerator::isContained(const Coordinate &target)
    {
        auto it = std::find_if(possibleMoves.begin(), possibleMoves.end(), [&](const std::shared_ptr<Coordinate> &coordinate)
                               { return *coordinate == target; });
        return it != possibleMoves.end();
    }
}

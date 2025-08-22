#include "models/pieces/rulesOfMovements/MovementRulesBaseGenerator.hpp"
#include "models/pieces/Piece.hpp"

namespace models::pieces::rulesOfMovements
{
    MovementRulesBaseGenerator::MovementRulesBaseGenerator() : piece(nullptr)
    {
    }

    MovementRulesBaseGenerator::MovementRulesBaseGenerator(Piece *piece) : piece(piece)
    {
    }

    void MovementRulesBaseGenerator::set(Piece *piece)
    {
        this->piece = piece;
    }

    std::list<std::shared_ptr<Coordinate>> MovementRulesBaseGenerator::getValidMovements()
    {
        return possibleMoves;
    }

    bool MovementRulesBaseGenerator::isMovementValid(const Coordinate &coordinate)
    {
        return isContained(coordinate);
    }

    bool MovementRulesBaseGenerator::isContained(const Coordinate &target)
    {
        auto it = std::find_if(possibleMoves.begin(), possibleMoves.end(), [&](const std::shared_ptr<Coordinate> &coordinate)
                               { return *coordinate == target; });
        return it != possibleMoves.end();
    }
}

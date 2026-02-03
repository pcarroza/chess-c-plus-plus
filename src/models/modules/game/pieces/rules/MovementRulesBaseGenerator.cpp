#include "models/modules/game/pieces/rules/MovementRulesBaseGenerator.hpp"
#include "models/modules/game/pieces/Piece.hpp"

namespace models::modules::game::pieces::rules
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

    std::list<std::shared_ptr<Coordinate>> &MovementRulesBaseGenerator::getMovements()
    {
        return possibleMoves;
    }

    bool MovementRulesBaseGenerator::isMovementValid(const Coordinate &coordinate)
    {
        return isContained(coordinate);
    }

    bool MovementRulesBaseGenerator::isContained(const Coordinate &target)
    {
        return std::any_of(possibleMoves.begin(), possibleMoves.end(), [&](const std::shared_ptr<Coordinate> &coordinate)
                           { return *coordinate == target; });
    }
}

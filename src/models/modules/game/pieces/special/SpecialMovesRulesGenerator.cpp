#include "models/modules/game/pieces/special/SpecialMovesRulesGenerator.hpp"

namespace models::modules::game::pieces::special
{
    SpecialMovesRulesGenerator::SpecialMovesRulesGenerator(Piece *piece)
        : piece(piece)
    {
    }

    std::vector<Coordinate> SpecialMovesRulesGenerator::getValidMovements()
    {
        return possibleMoves;
    }

    bool SpecialMovesRulesGenerator::isMovementValid(const Coordinate &coordinate) const
    {
        return isContained(coordinate);
    }

    bool SpecialMovesRulesGenerator::isContained(const Coordinate &coordinate) const
    {
        return std::any_of(possibleMoves.begin(), possibleMoves.end(), [&](const Coordinate &elem)
                           { return elem == coordinate; });
    }
}

#include "models/pieces/specialRuleMovements/SpecialMovesRulesGenerator.hpp"

namespace models::pieces::specialRuleMovements
{
    SpecialMovesRulesGenerator::SpecialMovesRulesGenerator(Piece *piece)
        : piece(piece)
    {
    }

    std::list<std::shared_ptr<Coordinate>> SpecialMovesRulesGenerator::getValidMovements()
    {
        return possibleMoves;
    }

    bool SpecialMovesRulesGenerator::isMovementValid(const Coordinate &coordinate)
    {
        return isContained(coordinate);
    }

    bool SpecialMovesRulesGenerator::isContained(const Coordinate &coordinate)
    {
        return std::any_of(possibleMoves.begin(), possibleMoves.end(), [&](const std::shared_ptr<Coordinate> &elem)
                           { return *elem == coordinate; });
    }
}

#include "models/pieces/Queen.hpp"

Queen::Queen(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    ruleBasedCoordinateGenerator = MovementRulesBaseGeneratorFacade::createQueenRuleBasedCoordinateGenerator(*this);
}

std::string Queen::toString() const
{
    return "Queen()";
}

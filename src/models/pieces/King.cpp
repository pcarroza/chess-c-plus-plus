#include "models/pieces/King.hpp"

King::King(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    ruleBasedCoordinateGenerator = MovementRulesBaseGeneratorFacade::createKingRuleBasedCoordinateGenerator(*this);
}

std::string King::toString() const
{
    return "King()";
}

#include "models/pieces/King.hpp"

King::King(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createKingRuleBasedCoordinateGenerator(*this);
}

std::string King::toString() const
{
    return "King()";
}

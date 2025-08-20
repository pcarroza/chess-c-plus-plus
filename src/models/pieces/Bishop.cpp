#include "models/pieces/Bishop.hpp"

Bishop::Bishop(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    ruleBasedCoordinateGenerator = MovementRulesBaseGeneratorFacade::createBishopRuleBasedCoordinateGenerator(*this);
}

std::string Bishop::toString() const
{
    return "Bishop()";
}

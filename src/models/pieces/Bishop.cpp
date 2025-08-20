#include "models/pieces/Bishop.hpp"

Bishop::Bishop(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createBishopRuleBasedCoordinateGenerator(*this);
}

std::string Bishop::toString() const
{
    return "Bishop()";
}

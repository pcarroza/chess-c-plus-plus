#include "models/pieces/Knight.hpp"

Knight::Knight(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createKnightRuleBasedCoordinateGenerator(*this);
}

std::string Knight::toString() const
{
    return "Knight()";
}

#include "models/pieces/Rook.hpp"

Rook::Rook(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    ruleBasedCoordinateGenerator = MovementRulesBaseGeneratorFacade::createRookRuleBasedCoordinateGenerator(*this);
}

std::string Rook::toString() const
{
    return "Rook()";
}

#include "models/pieces/Rook.hpp"

Rook::Rook(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createRookRuleBasedCoordinateGenerator(*this);
}

std::string Rook::toString() const
{
    return "Rook()";
}

#include "models/pieces/Rook.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Rook::Rook(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createRookRuleBasedCoordinateGenerator(this);
}

std::string Rook::toString() const
{
    return "Rook()";
}

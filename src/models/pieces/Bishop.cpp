#include "models/pieces/Bishop.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Bishop::Bishop(Coordinate *coordinate, Player color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createBishopRuleBasedCoordinateGenerator(this);
}

std::string Bishop::toString() const
{
    return "Bishop()";
}

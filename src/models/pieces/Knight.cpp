#include "models/pieces/Knight.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Knight::Knight(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createKnightRuleBasedCoordinateGenerator(this);
}

std::string Knight::toString() const
{
    return "Knight()";
}

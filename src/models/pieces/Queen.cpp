#include "models/pieces/Queen.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Queen::Queen(Coordinate *coordinate, Color color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createQueenRuleBasedCoordinateGenerator(this);
}

std::string Queen::toString() const
{
    return "Queen()";
}

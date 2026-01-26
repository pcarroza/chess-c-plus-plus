#include "models/pieces/King.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

King::King(Coordinate *coordinate, Player color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createKingRuleBasedCoordinateGenerator(this);
}

void King::accept(PieceVisitor &visitor)
{
    visitor.visit(*this);
}

std::string King::toString() const
{
    return "King()";
}

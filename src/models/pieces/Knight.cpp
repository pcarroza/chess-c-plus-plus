#include "models/pieces/Knight.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Knight::Knight(Coordinate *coordinate, Player color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createKnightRuleBasedCoordinateGenerator(this);
}

void Knight::accept(PieceVisitor &visitor)
{
    visitor.visit(*this);
}

std::string Knight::toString() const
{
    return "Knight()";
}

#include "models/pieces/Queen.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Queen::Queen(Coordinate *coordinate, Player color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createQueenRuleBasedCoordinateGenerator(this);
}

void Queen::accept(PieceVisitor &visitor)
{
    visitor.visit(*this);
}

std::string Queen::toString() const
{
    return "Queen()";
}

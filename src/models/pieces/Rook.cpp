#include "models/pieces/Rook.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Rook::Rook(Coordinate *coordinate, Player color) : Piece(coordinate, color)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createRookRuleBasedCoordinateGenerator(this);
}

void Rook::accept(PieceVisitor &visitor)
{
    visitor.visit(*this);
}

std::string Rook::toString() const
{
    return "Rook()";
}

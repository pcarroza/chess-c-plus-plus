#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::modules::game::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

namespace models::modules::game::pieces
{
    Bishop::Bishop(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = MovementRulesBaseGeneratorFacade::createBishopRuleBasedCoordinateGenerator(this);
    }

    void Bishop::accept(PieceVisitor &visitor)
    {
        visitor.visit(*this);
    }

    std::string Bishop::toString() const
    {
        return "Bishop()";
    }
}

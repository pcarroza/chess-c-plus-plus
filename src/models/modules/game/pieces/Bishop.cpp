#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/PieceVisitor.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"

using models::modules::game::pieces::rules::MovementRulesBaseGeneratorFacade;

namespace models::modules::game::pieces
{
    Bishop::Bishop(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = MovementRulesBaseGeneratorFacade::createBishopRuleBasedCoordinateGenerator(this);
    }

    void Bishop::accept(PieceVisitor &pieceVisitor)
    {
        pieceVisitor.visit(*this);
    }

    std::string Bishop::toString() const
    {
        return "Bishop()";
    }
}

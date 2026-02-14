#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"

namespace models::modules::game::pieces
{
    Rook::Rook(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = rules::createRookRuleBasedCoordinateGenerator();
    }

    void Rook::accept(PieceVisitor &pieceVisitor)
    {
        pieceVisitor.visit(*this);
    }

    std::string Rook::toString() const
    {
        return "Rook()";
    }
}

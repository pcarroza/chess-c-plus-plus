#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    Rook::Rook(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = const_cast<rules::MovementRulesGenerator *>(&rules::MovementRulesFacade::getRookRules());
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

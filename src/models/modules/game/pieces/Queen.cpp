#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    Queen::Queen(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = const_cast<rules::MovementRulesGenerator *>(&rules::MovementRulesFacade::getQueenRules());
    }

    void Queen::accept(PieceVisitor &pieceVisitor)
    {
        pieceVisitor.visit(*this);
    }

    std::string Queen::toString() const
    {
        return "Queen()";
    }
}

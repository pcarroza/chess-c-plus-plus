#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    Rook::Rook(Coordinate coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = &rules::MovementRulesFacade::getRookRules();
    }

    PieceSymbol Rook::getSymbol() const
    {
        return PieceSymbol::ROOK;
    }
}

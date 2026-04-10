#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    Queen::Queen(Coordinate coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = &rules::MovementRulesFacade::getQueenRules();
    }

    PieceSymbol Queen::getSymbol() const
    {
        return PieceSymbol::QUEEN;
    }
}

#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    Queen::Queen(Coordinate coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = const_cast<rules::MovementRulesGenerator *>(&rules::MovementRulesFacade::getQueenRules());
    }

    PieceSymbol Queen::getSymbol() const
    {
        return PieceSymbol::QUEEN;
    }
}

#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    Bishop::Bishop(Coordinate coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = const_cast<rules::MovementRulesGenerator *>(&rules::MovementRulesFacade::getBishopRules());
    }

    PieceSymbol Bishop::getSymbol() const
    {
        return PieceSymbol::BISHOP;
    }
}

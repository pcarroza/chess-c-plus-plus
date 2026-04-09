#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    Knight::Knight(Coordinate coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = const_cast<rules::MovementRulesGenerator *>(&rules::MovementRulesFacade::getKnightRules());
    }

    PieceSimbol Knight::getSymbol()
    {
        return PieceSimbol::KNIGHT;
    }
}
